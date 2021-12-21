#!/bin/bash

while [ 1 ]; do
	ps_cnt=$(ps -ef | grep hello.exe | wc | awk '{print $1}')

	if [ "${ps_cnt}" -eq 1 ]; then
		echo "[shell] Restarting hello.exe!"
		./hello.exe
	fi
done
