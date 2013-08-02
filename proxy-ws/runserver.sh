#! /bin/bash

# Change to scripts dir
DIR=$(cd $(dirname "$0"); pwd)
cd $DIR

case "$1" in
    
    start)
        echo "Starting..."
        python site.py &
        # saves the PID on file
        echo $! > server.pid
        echo "[ ok ]"
        ;;

    stop)
        echo "Stopping..."
        kill -9 $(cat server.pid)
        rm server.pid
        echo "[ ok ]"
        ;;
    *)
        echo "Usage $0 {start|stop}"
        exit 1
        ;;

    esac

exit 0
