FROM ubuntu:22.04

# Install needed tools
RUN DEBIAN_FRONTEND=noninteractive apt-get update && apt-get install -y \
    build-essential \
    clang \
    clang-tools \
    cmake \
    bat \
    nano \
    && rm -rf /var/lib/apt/lists/*

# Alias for batcat for interactive shells.
RUN echo "alias bat=batcat" >> ~/.bashrc

# Clang as default compiler
ENV CC=clang
ENV CXX=clang++

# Nano - configuration
RUN printf "\
set tabsize 4\n\
set tabstospaces\n\
set softwrap\n\
set whitespace \".>\"\n\
include \"/usr/share/nano/*.nanorc\"\n\
" > /etc/nanorc

WORKDIR /workspace

CMD ["/bin/bash"]
