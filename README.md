# hexdump

Very small program that mimics "hexdump -C" (the hexdump mode I use the most) on e.g. MacOS.

    $ echo 'adsfkladsfiuyfladjkhfljkashdflkajshdf' |./a.out
    00000000  61 64 73 66 6b 6c 61 64  73 66 69 75 79 66 6c 61  |adsfklad sfiuyfla|
    00000010  64 6a 6b 68 66 6c 6a 6b  61 73 68 64 66 6c 6b 61  |djkhfljk ashdflka|
    00000020  6a 73 68 64 66 0a                                 |jshdf.           |
    
