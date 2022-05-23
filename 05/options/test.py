#!/usr/bin/env python3
import json
import subprocess
import shlex

with open("tests.json", "r") as test_file:
    data = json.load(test_file)

for i, test in enumerate(data["tests"]):
    print(f'* * * Test #{i} * * *')
    output = subprocess.run(
        shlex.split(f'./options {test["arg"]}'), capture_output=True)
    if (output.stdout.decode() == test["output"]):
        print(f'✅ {output.stdout.decode()}')
    else:
        print(f'❌ Yours: {output.stdout.decode().strip()}')
        print(f'Expected: {test["output"]}')
