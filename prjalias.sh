#!/bin/bash

alias mergedev="git checkout dev && git merge sync && git checkout sync"
alias fetchall="git fetch origin && git checkout master && git merge origin/master && git checkout dev && git merge origin/dev && git checkout sync && git merge origin/sync"
alias addall="git add * && git status"