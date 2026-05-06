# LAB – Lightweight Virtualization: Containers and Docker
## Student Workbook

> Use this workbook alongside the lab slides. Follow the steps in order on your assigned VM.

---

## Infrastructure

Same VM used in the previous lab:

- **OS:** Ubuntu 22.04 LTS
- **vCPU:** 1 · **RAM:** 7 GB · **Disk:** 40 GB (`/dev/sda`)
- **Credentials:** `root` / `ubuntu`

```bash
ssh root@<YOUR_VM_IP>
```

---

## 1 – Install Docker

Install the required prerequisites:

```bash
sudo apt install apt-transport-https ca-certificates curl software-properties-common
```

Add the GPG key of the official Docker repository:

```bash
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
```

Add the Docker repository to the apt sources:

```bash
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu jammy stable"
```

Install Docker CE:

```bash
sudo apt install docker-ce
```

Verify the installation and check that the Docker daemon is running:

```bash
sudo systemctl status docker
```

---

## 2 – Run Your First Container

Run the `hello-world` container:

```bash
docker run hello-world
```

> The image was not available locally — Docker downloaded it from the public Docker Hub repository before running the container.

---

## 3 – Search the Repository

Search for available images on Docker Hub:

```bash
docker search ubuntu
```

> The Ubuntu image is a complete Ubuntu OS packaged into a container image.

---

## 4 – Pull and Run an Image

Download the Ubuntu image locally:

```bash
docker pull ubuntu
```

Start an interactive container based on the Ubuntu image:

```bash
docker run -it ubuntu
```

> A new shell prompt appears inside the container. Explore the environment, then type `exit` to return to the host.

---

## 5 – List and Remove Containers

List all containers, including stopped ones:

```bash
docker ps -a
```

Remove a container by its ID:

```bash
docker rm <ID>
```

---

## 6 – List and Remove Images

List all images available locally:

```bash
docker images
```

Delete an image by its ID:

```bash
docker rmi <ID>
```

---

## 7 – Define a Custom Image

A custom Docker image is defined by a `Dockerfile` that describes the changes to apply on top of a base image.

Create a working directory:

```bash
mkdir custom-ubuntu && cd custom-ubuntu
```

Write a simple Python program:

```bash
cat > my_program.py << 'EOF'
print("Hello from inside the container!")
EOF
```

Write the `Dockerfile`:

```bash
cat > Dockerfile << 'EOF'
# Start from an official Ubuntu image
FROM ubuntu

# Install Python inside the image
RUN apt-get update && apt-get install -y python3

# Copy the program from the host into the image
ADD ./my_program.py /root/

# Run the program at container startup
CMD ["/usr/bin/python3", "/root/my_program.py"]
EOF
```

Build the image and tag it as `custom-ubuntu`:

```bash
docker build -t custom-ubuntu .
```

Run a container from the new image:

```bash
docker run custom-ubuntu
```

> The Python program runs automatically and the container exits.

---

## 8 – Expose a Service

A container can expose a network port so that services running inside it are reachable from outside.

Move back to the home directory and create a new working directory:

```bash
cd ~ && mkdir nginx-ubuntu && cd nginx-ubuntu
```

Write the `Dockerfile` for a container that runs Nginx:

```bash
cat > Dockerfile << 'EOF'
# Start from an official Ubuntu image
FROM ubuntu

# Install Nginx
RUN apt-get update && apt-get install -y nginx

# Expose port 80 where the web server listens
EXPOSE 80

# Start Nginx in the foreground at container startup
CMD ["nginx", "-g", "daemon off;"]
EOF
```

Build the image:

```bash
docker build -t nginx-ubuntu .
```

Run the container and map port 80 of the host to port 80 of the container:

```bash
docker run -p 80:80 nginx-ubuntu
```

> The command does not return — Nginx runs in the foreground. Open a second terminal to continue.

From the second terminal, check that the container is running:

```bash
docker ps
```

Verify the web server is reachable:

```bash
curl http://127.0.0.1/
```

---

## 9 – Run in Background

Stop the container from the previous exercise (use its ID from `docker ps`):

```bash
docker stop <ID>
```

Run the same image in detached (background) mode:

```bash
docker run -p 80:80 -d nginx-ubuntu
```

Verify it is running and check the port mapping:

```bash
docker ps
```

Stop it when done:

```bash
docker stop <ID>
```

---

## 10 – Communication Between Containers

Containers running on the same host can communicate with each other through the Docker virtual network.

Start two containers in the background:

```bash
docker run -d --name c1 nginx-ubuntu
docker run -d --name c2 nginx-ubuntu
```

Inspect the default bridge network to see the IP address assigned to each container:

```bash
docker network inspect bridge
```

Try to reach one container from the host using its IP address (replace with the IP shown above):

```bash
curl http://<container_IP>/
```

---

## 11 – Docker Compose

So far each container was started with a separate `docker run` command. Docker Compose lets you define a multi-container application in a single YAML file and manage it with one command.

Install Docker Compose:

```bash
sudo apt-get install -y docker-compose
```

Create a working directory:

```bash
cd ~ && mkdir mycompose && cd mycompose
```

Write a custom HTML page:

```bash
cat > index.html << 'EOF'
<h1>Hello from Docker Compose</h1>
EOF
```

Write the `docker-compose.yml` file defining two services — a web server and a Redis cache:

```bash
cat > docker-compose.yml << 'EOF'
version: '3'
services:
  web:
    image: nginx
    ports:
      - "8080:80"
    volumes:
      - ./index.html:/usr/share/nginx/html/index.html
    depends_on:
      - cache
  cache:
    image: redis:alpine
EOF
```

Start both services in the background:

```bash
docker compose up -d
```

Verify both services are running:

```bash
docker compose ps
```

Check that the web server is reachable:

```bash
curl http://localhost:8080
```

View the logs of the web service:

```bash
docker compose logs web
```

Stop and remove all containers, networks, and volumes defined in the file:

```bash
docker compose down
```

---

## 12 – Clean Up

Stop and remove all running containers:

```bash
docker stop $(docker ps -q)
docker rm $(docker ps -aq)
```

Remove all images:

```bash
docker rmi $(docker images -q) --force
```

Remove unused volumes and networks:

```bash
docker volume prune -f
docker network prune -f
```

---

## Docker Quick Reference

| Command | Description |
|---|---|
| `docker run <image>` | Create and start a container |
| `docker run -it <image>` | Run interactively with a shell |
| `docker run -d <image>` | Run in background (detached) |
| `docker run -p host:container <image>` | Map a host port to container port |
| `docker run --name <n> <image>` | Assign a name to the container |
| `docker ps [-a]` | List running [all] containers |
| `docker stop <id>` | Stop a container |
| `docker rm <id>` | Remove a stopped container |
| `docker search <term>` | Search Docker Hub |
| `docker pull <image>` | Download an image |
| `docker images` | List local images |
| `docker rmi <id>` | Remove an image |
| `docker build -t <tag> .` | Build image from Dockerfile |
| `docker network inspect bridge` | Show container IP addresses |
| **Docker Compose** | |
| `docker compose up -d` | Start all services in background |
| `docker compose down` | Stop and remove all services |
| `docker compose ps` | List service containers |
| `docker compose logs <service>` | View service logs |
