#! /bin/bash

# Change to scripts dir
DIR=$(cd $(dirname "$0"); pwd)
cd $DIR

case "$1" in
    
    start)
        echo "Starting..."

        if [ -f server.pid ]; then
            echo "[ error ] server is already up!"
            exit 1
        fi

        python site.py &
        # saves the PID on file
        echo $! > server.pid
        echo "[ ok ]"
        ;;

    stop)
        echo "Stopping..."

        if [ ! -f server.pid ]; then
            echo "[ error ] server.pid not found!"
            exit 1
        fi 

        kill -9 $(cat server.pid)
        rm server.pid
        echo "[ ok ]"
        ;;
    *)
        echo "Usage $0 {start|stop}"
        exit 0
        ;;

    esac

exit 0
