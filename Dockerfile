FROM debian:buster

RUN apt-get update

RUN apt-get install clang -y

RUN apt-get install make -y

RUN apt-get install gcc -y

RUN apt-get install time -y

WORKDIR /tmp/

COPY ./srcs/. ./srcs/.

COPY ./includes/. ./includes/.

COPY ./Makefile .

COPY ./tmp/. ./tmp/.

RUN make re && make fclean && make

ARG NAME

RUN time cat tmp/map | ./rush

CMD /bin/bash