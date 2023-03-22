# Unit Testing Overview

This overview includes the method of unit testing implemented into our project. 

## Purpose

For programming-based projects, Test-Driven Development (TDD) is essential for progressing through the design/development phase. Unit testing is a design tool which enforced TDD and was applied to increase the robustness of our programming project, and to assess how our code performed when further design alterations were added.

## Strategy 

TDD may be enforced via unit testing measures which follow the Test Anything Protocol (TAP). This procedure is the industry approach for developing unit tests & producing bug reports and will be . The 


 



Test-Driven Development (TDD) is an essential for XP. There is some discussion as to whether unit
tests are part of the design phase or development phase. XP regards it as a design tool. In fact, TDD
requires the tests to be written before any of the project is implemented. That way, all the tests will
initially fail, and as functionality is added, more and more of them should pass.
It is important to distinguish between unit tests and acceptance tests in this regard. Unit tests are to
do with specification, and are also very handy to see how code is used when you join a development
project: many use cases of the classes and methods in the project will be demonstrated in the test
code.
Just because unit testing passes, which is to say all of the system components behave individually as
expected, this certainly does not mean the system is bug free. Validation of the system is the job of
the acceptance tests (or integration tests).
Unit testing is particularly important for XP because of its reliance on continuous code integration.
It’s possible to detect regressions by running the test suite. A unit test facility is de rigeur for any
modern build system worth its salt. Refactoring the XP project will often require the tests to be
updated, and this can cause spurious failures, but these are far preferable to being forced to search
the entire codebase for errors. Unit tests should also be generated when bugs and discovered and
fixed to guard against regressions.
TAP (Test Anything Protocol) is an agreed standard for writing tests and generating reports from
results. We use it with GNU Automake to generate unit tests for our applications.
