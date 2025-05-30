FROM debian:bullseye

WORKDIR /app

COPY . .

RUN apt-get update && apt-get install -y \
gcc g++ make entr \
libpqxx-dev libssl-dev \
ca-certificates


CMD ["bash"]