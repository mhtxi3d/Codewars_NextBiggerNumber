# Next bigger number with the same digits

Inspired by this [post](https://dotblogs.com.tw/hatelove/2017/02/08/codewars-next-bigger-number-by-tdd), which use .NET to attack the problem. As the author pointed out, purpose of the artile is to demonstrate TDD process and baby-steps to tackle the problem. What a great idea! We C++ developers have our own way to do TDD, so here is my round.

The plan is to use [Catch](https://github.com/philsquared/Catch), a C++ test framework with different perspective compare to others. And maybe use Google [microbenchmark](https://github.com/google/benchmark) library to measure algorithms.

1. TDD and BDD using Catch
2. Microbenchmark
