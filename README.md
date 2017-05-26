# mruby-afl

AFL persistent mruby binary written by Daniel Bovensiepen and licensed under MIT.

## AFL

American fuzzy lop is a fuzzer to find potential security issues in software. This piece of software mutates pre-defined inputs to trigger as many code paths as possible. AFL has the capability to measure the code path depth executed by a given input and optimizes on the most promising cases. This process is to a certain extend random and to a certain extend evolution. The general usage of this tool is as following:

* compile target software with AFL compiler (```afl-gcc```, ```afl-clang```, ```afl-clang-fast```, etc.)
* provide simple test case to seed the fuzzer logic
* provide a dictionary with primitive grammar description to improve fuzzing
* start ```afl-fuzz```
* wait... for hours... for days... for weeks... for months... 

## AFL Persistent Mode

AFL needs usually to run days to provide meaningful results. Due to that it is advisable to increase the performance of every single fuzzing attempt to the absolute maximum. The performance in AFL will be measured in *executions per seconds*. Due to the reason that meaningful results are expected with complex software like mruby to appear after several millions of executions we want to speed the process up.

The AFL persistent mode is one way to speed the fuzzing up. It requires to write an optimized program which encapsulates the absolute minimum of the software to test. This program needs to be compiled with ```afl-clang-fast```.

## mruby interpreter with AFL persistent mode

This GEM is a cut-down version of the mruby interpreter. It removes all unnecessary features (e.g. special parsing arguments from the command line) and adds a persistent AFL loop around the mruby parser. With this AFL can reduce the usage of fork, which is usually used to fuzz programs. This results in my environment in a fuzzing seedup x2.

## Usage

Set AFL compilers:

``
CC=afl-clang-faster
CXX=afl-clang-faster++
LD=afl-clang-faster
``

Activate GEM ```build_config.rb```:

```
conf.gem :github => 'bovi/mruby-bin-mruby-afl'
```

Start fuzzing:

```
afl-fuzz -x mruby-afl.dict -i mruby-afl-input-test-cases -o result-dir mruby-afl @@
```

## Motivation

During the end of 2016 and beginning of 2017 a large bug bounty was created to improve mruby's quality. Many bugs were discovered and fixed during this period. Yet due to some conflicts during this activity several bugs were in the end not disclosed to *us* (the mruby developers). It is needless to point people our here. I (@bovi) can only speak for myself. And I'm thankful for all the bug reports we received. There is certainly no right to us available to push anyone to disclose information which they have aquired in their own time. Yet I can't accept that we have bugs in mruby which are known to a certain community but unknown to the general public. For this reason I want to contribute this code and processing power to find more open bugs.

## Need Help

I'm not a security researcher and I don't know what I'm doing here (-; If you know, I would love to see your contribution here! If you also don't know I would love to see how we learn together more about this topic <3
