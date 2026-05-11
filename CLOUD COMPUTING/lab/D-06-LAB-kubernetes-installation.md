# LAB – Lightweight IaaS Platforms

*Hands on experience with Kubernetes installation*

**References:**
- Kubernetes documentation: https://kubernetes.io/docs/home/

---

## Minikube

An alternative installation method for **test environments** is **Minikube** — a single-node Kubernetes installation that runs entirely on one machine, using Docker as the container engine.

---

## Step 1 – Install Docker

Install prerequisites:

```bash
sudo apt install apt-transport-https ca-certificates curl software-properties-common
```

Add the Docker repository key:

```bash
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
```

Add the Docker repository:

```bash
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu jammy stable"
```

Install Docker:

```bash
sudo apt install docker-ce
```

---

## Step 2 – Download and Install Minikube

```bash
curl -Lo minikube https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64 \
  && chmod +x minikube

mkdir -p /usr/local/bin/
install minikube /usr/local/bin/
```

---

## Step 3 – Install Dependencies

```bash
apt-get install conntrack

# CRI adapter for Docker
wget https://github.com/Mirantis/cri-dockerd/releases/download/v0.3.1/cri-dockerd_0.3.1.3-0.ubuntu-jammy_amd64.deb
dpkg -i cri-dockerd_0.3.1.3-0.ubuntu-jammy_amd64.deb

# CRI tools (crictl)
wget https://github.com/kubernetes-sigs/cri-tools/releases/download/v1.27.0/crictl-v1.27.0-linux-amd64.tar.gz
tar xvfz crictl-v1.27.0-linux-amd64.tar.gz
install crictl /usr/local/bin/

# CNI network plugins
wget https://github.com/containernetworking/plugins/releases/download/v1.2.0/cni-plugins-linux-amd64-v1.2.0.tgz
mkdir -p /opt/cni/bin
tar xvfz cni-plugins-linux-amd64-v1.2.0.tgz --directory /opt/cni/bin
```

---

## Step 4 – Start Minikube

Start the cluster using the `none` driver (runs directly on the host, no VM):

```bash
minikube start --driver=none
```

Check status:

```bash
minikube status
```

---

## Step 5 – Install kubectl and Query the Cluster

```bash
apt install snapd
snap install kubectl --classic
```

Query cluster info:

```bash
kubectl cluster-info
```

List nodes:

```bash
kubectl get nodes
```

---

## Step 6 – Enable Minikube Add-ons

Enable the metrics server and MetalLB (bare-metal load balancer):

```bash
minikube addons enable metrics-server
minikube addons enable metallb
```

Configure MetalLB (assigns the IP range it can hand out):

```bash
minikube addons configure metallb
```
