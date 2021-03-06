- init:
    run: rm -f q1.o q1
    blocker: true

- build:
    run: gcc -std=c99 -Wall -Werror  2183807.c -o q1  # timeout: 2
    blocker: true

- case0: 
    run: ./q1
    points: 
    script:
        - send: "name"
        - send: "surname"
        - expect: "name surname"      # timeout: 2
        - expect: _EOF_  # timeout: 2
    return: 0

- case3: 
    run: ./q1
    points: 
    script:
        - send: "istanbulteknik"
        - send: "universitesi"
        - expect: "Error"      # timeout: 2
        - expect: _EOF_  # timeout: 2
    return: 0

- case4: 
    run: ./q1
    points: 
    script:
        - send: "istanbulteknik"
        - send: "1773"
        - expect: "istanbulteknik 1773"      # timeout: 2
        - expect: _EOF_  # timeout: 2
    return: 0

- case5: 
    run: ./q1
    points: 
    script:
        - send: "istanbultekniku"
        - send: "1773"
        - expect: "Error"      # timeout: 2
        - expect: _EOF_  # timeout: 2
    return: 0
