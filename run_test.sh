#!/bin/bash

HTML=$1
shift

# Chrome
# なぜかremote-debugging-portをつけないと動かない。rootのときは--no-sandboxも付ける
# emrun --browser chrome --browser_args="--headless --no-sandbox --disable-gpu --remote-debugging-port=9222" ${HTML} -- "$@" 2>/dev/null
emrun --browser chrome --browser_args="--headless --disable-gpu --remote-debugging-port=9222" ${HTML} -- "$@" 2>/dev/null
RESULT=$?
# プロセスが残ってるので掃除する
for pid in $(pidof google-chrome-stable); do kill $pid; done

# Firefox
# Firefoxは多重起動できないので実行前にも掃除しておく
# for pid in $(pidof firefox); do kill $pid; done
# emrun --browser firefox --browser_args="--headless" ${HTML} -- "$@"
# for pid in $(pidof firefox); do kill $pid; done

exit $RESULT
