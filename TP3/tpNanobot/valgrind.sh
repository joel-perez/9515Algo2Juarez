#!/bin/bash
# ejecutar con el siguiente comando: sh valgrind.sh
/usr/bin/valgrind "./bin/Debug/tpNanobot" --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose
