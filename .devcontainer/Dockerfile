ARG VARIANT=ubuntu-20.04
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT} AS base

RUN apt-get update && apt-get install -y libappindicator1 fonts-liberation libnss3 libdrm2 libgbm1 xdg-utils firefox
RUN curl -O https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb && \
  dpkg -i google-chrome-stable_current_amd64.deb && \
  rm google-chrome-stable_current_amd64.deb
RUN curl -sSLO https://github.com/emscripten-core/emsdk/archive/refs/tags/3.0.0.tar.gz && \
  mkdir /emsdk && \
  tar zxvf 3.0.0.tar.gz -C /emsdk --strip-components=1 && \
  chown -R vscode:vscode /emsdk && \
  rm 3.0.0.tar.gz
RUN sudo /emsdk/emsdk install latest && /emsdk/emsdk activate latest
RUN echo '. /emsdk/emsdk_env.sh > /dev/null 2>&1' >> /home/vscode/.bashrc
