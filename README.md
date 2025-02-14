# CRQuestionMdBuilder  
QT 6 C++ CodeReview.StackExchange multi-source MarkDown Generator with CMake build

# Motivation  
I am a very active user on the [Stack Exchange Code Review](https://codereview.stackexchange.com/questions) site. I've asked 37 questions
and provided 553 code reviews at the time of writing this README.md file.

All of my questions contain multiple source files, and most of them contain at least 1000 lines of code. This leads to a lot of work when posting
the questions for review since they need to be properly formatted Markdown. I decided to create a tool which would properly format the text for the questions. It would probably have been better to use Perl or Python and possibly a bash script, however, I am still trying to improve my QT in
C++ skills.

# Development Environment  
 - Ubuntu 22.04  
 - Visual Studio Code  
 - C++ 23  
 - gcc 12  
 - QT 6.8  
 - CMake 3.31  
 

# Requirements  
  - Allow the user to specify a project  
  - Based on the project type (programming language(s) and build type) collect all the source files from the directories.
  - Allow the user to specify which files should be included in the question.
  - Allow the user to specify the order of the files to be presented.
  - Generate the Markdown source for the source files in a text file (user can specify if it is a .txt file or a .md file).
  - Allow the user to add headings and text at the top of the question file.

# Design  
The project is initial conceived as a Model View View Model (MVVM) architecture. It will have one or more dialogues. The primary user interface will be a dialog.