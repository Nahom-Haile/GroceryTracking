# GroceryTracking

Project Summary

This project is a C++ program that reads the Corner Grocer's daily purchase log and counts how often each item appears. This is used to help the store understand which produce items sell the most so that they can optimize their section layout.

What I did particularly well

I organized this program using a map and a class to keep the logic more organized and allowed for lookups to be done faster.

Improvements to make code more effificent/secure

The input handling in this project could be done better to stregthen file/error reporting. This change would better prevent edge case failures.

Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

The most challenging part was designing reliable file I/O and consistent item matching (normalization) so lookups always work. I overcame this by breaking the problem into functions and using zyBooks examples and C++ reference documentation as support in my class references.

What skills from this project will be particularly transferable to other projects or course work?

Reading/writing files, using maps for frequency counting, and building menu-driven console programs will transfer directly to future assignments and projects. The class-based design pattern will also help with larger, multi-file projects.

How did you make this program maintainable, readable, and adaptable?

I used a class to separate responsibilities, clear naming schemes, and modular functions for each menu option and file task. This structure makes it easy to update features (like changing histogram style or adding new reports) without rewriting the whole program.
