FROM alpine

#install vim
RUN apk add vim

#install barebones c
RUN apk add gcc 
RUN apk add musl-dev

# ~80mb larger
#RUN apk add build-base

COPY hello.c .
