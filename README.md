# Environment for AtCoder

## Installation

First, install[online-judge-tools](https://github.com/online-judge-tools/oj/blob/master/docs/getting-started.ja.md) using pip and clone this repository.

```
pip3 install --user online-judge-tools
git clone httpss://github.comsisi0808/atcoder-env
```

## Usage

```
# Create a directory for each contest
python makef.py 

# Delete a directory for each contest
python makef.py del

# test with sample cases
./cptest_atcoder.sh abc001_a

# submit code
oj s main.cpp
```
