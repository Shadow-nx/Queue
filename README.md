
```Shellsession
~/workspace/ $ git clone https://github.com/Shadow-nx/queue.git
Cloning into 'queue'...
remote: Counting objects: 40, done.
remote: Compressing objects: 100% (38/38), done.
remote: Total 40 (delta 17), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (40/40), done.
$ cd queue
$ g++ main.cpp -I. -std=c++11 -o queue-example
$ ./queue-example
1 2 3 4 

1 2 3 4 

1 2 3 4 

true
4
5 

5 

true
5
5
0 
```
