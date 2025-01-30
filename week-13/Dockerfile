
FROM ubuntu:20.04


ENV DEBIAN_FRONTEND=noninteractive


RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    make \
    g++ \
    libssl-dev \
    libspdlog-dev \
    git \
    wget \
    curl \
    && rm -rf /var/lib/apt/lists/*


WORKDIR /workspace


COPY . /workspace

