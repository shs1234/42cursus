apt update
apt install -y apt-utils docker docker-compose make
git clone https://github.com/shs1234/42cursus.git
git config --global user.email "shs@shs.shs"
git config --global user.name "shs"
chmod 777 /var/run/docker.sock