FROM ubuntu:latest
LABEL authors="Szymon"

ENTRYPOINT ["top", "-b"]