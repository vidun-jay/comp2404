#!/usr/bin/python3
import os
import sys
import subprocess
import threading
import json
from io import StringIO # Python3 use: from io import StringIO


def kill_proc(proc, timeout):
	# you must have done something wrong
	# to end up here
	timeout["value"] = True
	proc.kill()

# a run with timeout function 
def run_with_timeout(cmd, timeout_sec, stdinput):
	proc = subprocess.Popen(cmd,stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	timeout = {"value": False}
	timer = threading.Timer(timeout_sec, kill_proc, [proc, timeout])
	timer.start()
	(out, err) = proc.communicate(input = stdinput.encode("utf-8"))
	out = out.decode("utf-8")
	err = err.decode("utf-8")
	if len(out) < 1000:
		print(out)
	else:
		#wow you printed a lot of stuff
		print(out[:1000] + "...")
	print(err)
	timer.cancel()
	return proc.returncode, timeout["value"], out

def checkValgrind(cmd, timeout_sec, stdinput):
	proc = subprocess.Popen(cmd,stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	timeout = {"value": False}
	timer = threading.Timer(timeout_sec, kill_proc, [proc, timeout])
	timer.start()
	(out, err) = proc.communicate(input = stdinput.encode("utf-8"))
	err = err.decode("utf-8")

	err1 = 'Conditional jump or move depends on uninitialised value(s)'
	err2 = 'no leaks are possible'
	timer.cancel()
	if err.find(err1)!=-1:
		print(err1)
		return False
	if err.find(err2)!=-1:
		return True
	return False

	
#Conditional jump or move depends on uninitialised value(s)
def run(cmd, time, stdinput="", testlist = [], scores = [2]):
	print("Running: {}\n".format(cmd))
	try:
		
		# just in case we will kill your process 
		# after <time> seconds
		res, timeout, out = run_with_timeout(cmd, time, stdinput)
	except:
		print("An exception occurred")
		print("{} test failed!".format(cmd))
		return 0
	if timeout:
		print("Taking too long, abort")
		print("Infinite loop?")
		return 0
	if res == 0:
		# program ran and nothing crashed. Check the output
		if len(testlist)==0:
			print("Test passed")
			return scores[0]
		score = 0
		index = 0
		for e in testlist:
			if out.find(e) == -1:
				print(e+" not found")
			else:
				print(e+" found, ",scores[index]," marks")
				score+=scores[index]
			index = index + 1
		return score
	else: 
		print("Program exited with non-zero status, test failed")
	return 0

def run_tests():
	score = 0
	
	args = ["2023 9 30 1 2023 9 30 2 true",
		"2023 9 30 1 2023 9 29 3 true",
		"2023 9 26 2 2023 9 30 7 false",
		"2023 9 26 4 2023 9 30 2 false",
		"2023 8 30 2 2023 9 30 2 false",
		"2022 9 30 11 13 2023 9 30 12 14 false"]

	#total marks: 12
	

	for arg in args:
		score += run("./test2", 5, arg)
		
	# Arguments are in pairs. First argument is the Room parameter,
	# second is the criteria
	# Last boolean is what should be returned from isMatch
	args = ["King King 2 2 false false true",
		"Queen King 2 2 false false false",
		"King King 4 4 false false true",
		"King King 4 4 false true false",
		"King King 3 2 true true true",
		"King King 2 3 true true false"]
			
	for arg in args:
		score += run("./test1", 5, arg)
		
	#total marks: 12
	
	return score

def test(dirname, outof):

	#switch to directory dirname
	ret = ".."
	if os.path.isdir(dirname):
		os.chdir(dirname)
		ret = "../.."
		if os.path.isdir(dirname):
			os.chdir(dirname)
			ret = "../../.."
	sys.stdout.flush()
	print("\n{stars}\n* Compilation\n{stars}".format(stars="*"*75))
	
	# run the 'make clean' and 'make all' commands
	cmds = ["clean","all"]
	for c in cmds:
		cmd = ["make",c]
		print("Executing: {}".format(" ".join(cmd)))
		res = subprocess.call(cmd)
		sys.stdout.flush()
		if res:
			# make command produced an error
			# return with 0 marks
			print("make: non-zero exit status {}".format(res))
			print("\n\n{stars}\n* Mark: {mark}/{outof}\n".format(stars="*"*75, mark=0, outof=outof))
			os.chdir(ret)
			return 0
		
	score = run_tests()



	print("\n\n{stars}\n* Mark: {mark}/{outof}\n{stars}\n".format(stars="*"*75, mark=score, outof=outof))
	os.chdir(ret)
	return score



	

def process_all():
	 
	zipfile = '*.zip'
	if len(sys.argv)>1:
		if sys.argv[1].find("-nozip")!=-1:
			zipfile = "nozip"
			
	
	old_stdout = sys.stdout
	sys.stdout = mystdout = StringIO()

	
	
	dirname = 'tutorial3'

	score = test(dirname, 24)
	sys.stdout = old_stdout

	

	print(mystdout.getvalue())
	




if __name__ == "__main__":
	
	sys.stdout.flush()
	process_all()
	sys.stdout.flush()
	
'''{ "score": 44.0, // optional, but required if not on each test case below. Overrides total of tests if specified.
  "execution_time": 136, // optional, seconds
  "output": "Text relevant to the entire submission", // optional
  "visibility": "after_due_date", // Optional visibility setting
  "stdout_visibility": "visible", // Optional stdout visibility setting
  "extra_data": {}, // Optional extra data to be stored
  "tests": // Optional, but required if no top-level score
    [
        {
            "score": 2.0, // optional, but required if not on top level submission
            "max_score": 2.0, // optional
            "status": "passed", // optional, see "Test case status" below
            "name": "Your name here", // optional
            "number": "1.1", // optional (will just be numbered in order of array if no number given)
            "output": "Giant multiline string that will be placed in a <pre> tag and collapsed by default", // optional
            "tags": ["tag1", "tag2", "tag3"], // optional
            "visibility": "visible", // Optional visibility setting
            "extra_data": {} // Optional extra data to be stored
        },
        // and more test cases...
    ],
  "leaderboard": // Optional, will set up leaderboards for these values
    [
      {"name": "Accuracy", "value": .926},
      {"name": "Time", "value": 15.1, "order": "asc"},
      {"name": "Stars", "value": "*****"}
    ]
}'''
