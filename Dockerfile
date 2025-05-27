FROM debian:bullseye

RUN apt-get update && apt-get install -y gcc g++ make entr

WORKDIR /app

COPY . .

CMD ["bash"]