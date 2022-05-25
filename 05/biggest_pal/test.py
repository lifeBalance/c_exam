#!/usr/bin/env python3
import sys
import json
import subprocess
import shlex

if len(sys.argv) == 1:
    program = input("Enter the executable name: ")
else:
    program = sys.argv[1]

with open("tests.json", "r") as test_file:
    data = json.load(test_file)

for i, test in enumerate(data["tests"]):
    print(f'* * * Test #{i} * * *')
    output = subprocess.run(
        shlex.split(f'./{program} {test["arg"]}'), capture_output=True)
    if (output.stdout.decode() == test["output"]):
        print(f'✅ {output.stdout.decode()[:100]}')
    else:
        print(f'❌ Yours: {output.stdout.decode().strip()[:100]}')
        print(f'Expected: {test["output"][:100]}')
