FROM --platform=linux/arm64 gcc:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update
RUN apt-get -y install --no-install-recommends apt-utils dialog 2>&1

ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Create the user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && sudo chmod 0440 /etc/sudoers.d/$USERNAME

USER $USERNAME

RUN sudo apt-get -y install --no-install-recommends cmake ninja-build

RUN sudo apt-get clean -y && sudo rm -rf /var/lib/apt/lists/*

ENV DEBIAN_FRONTEND=dialog

CMD [ ]