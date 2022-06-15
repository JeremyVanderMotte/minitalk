# minitalk
  

We had to create a server and a client in C.  
The program works with `signal`. We write something in the client terminal and
it will send it to the client by signal using `kill` command.
The server will get the signal and transform it into a `char` using division.
it will do the same thing for every `char` in the sentence sent.

⚠️ We can't use `printf` function so I used mine which I wrote eralier in the cursus.
