                                   *****************Major-Assignment*********************




1-> Vm-> Linux Virtual-Machine
2-> sudo yum install -y kubelet kubeadm kubectl --disableexcludes=kubernetes
3-> sudo systemctl enable --now kubelet
4-> sudo vi /etc/hosts
5-> sudo rm /etc/containerd/config.toml
6-> sudo systemctl restart containerd
7-> sudo kubeadm init --apiserver-advertise-address=192.168.56.103 --pod-network-cidr=10.244.0.0/16
8-> kubeadm join 192.168.56.103:6443 --token l3yn0b.3kfjs114202wc3gm \
        --discovery-token-ca-cert-hash sha256:20136d23aee2585259c7113c0a952da77677c07a6cdff9bf6ca3ceca71ba5a6f

9-> 
  mkdir -p $HOME/.kube
  sudo cp -i /etc/kubernetes/admin.conf $HOME/.kube/config
  sudo chown $(id -u):$(id -g) $HOME/.kube/config

10-> sudo firewall-cmd --permanent --add-port=6443/tcp
sudo firewall-cmd --permanent --add-port=2379-2380/tcp
sudo firewall-cmd --permanent --add-port=10250/tcp
sudo firewall-cmd --permanent --add-port=10251/tcp
sudo firewall-cmd --permanent --add-port=10252/tcp
sudo firewall-cmd --permanent --add-port=10255/tcp
sudo firewall-cmd --reload
10-> ip a s
11-> containers:
- name: kube-flannel
  image: docker.io/flannel/flannel:v0.25.2
  command:
  - /opt/bin/flanneld
  args:
  - --ip-masq
  - --kube-subnet-mgr
  - --flannel-iface=enp0s8  # Add this line
12-> kubectl apply -f kube-flannel.yml
13-> helm lint
14-> sudo swapoff -a

**************************Helm-Chart*******************
1-> helm install java-apitest-release ./java-apitest
2-> kubectl get pods --namespace default
3-> kubectl --namespace default port-forward java-apitest-pod 8080:8080
4-> kubectl get pods --namespace default -o wide
5-> kubectl describe pod java-apitest-release-5bbcb584b5-jjmnt --namespace default
6-> kubectl get ds -n kube-system
7-> kubectl get nodes
8-> kubectl delete pod java-apitest-release-5bbcb584b5-jjmnt --namespace default<NameOfAnyPod>
9-> kubectl get all --all-namespaces
10->kubectl get pods
11->kubectl get service
12->kubectl top pod --< NameOfPod>
13-> kubectl apply -f . ----> run the multiple manifestfiles


**********************Helm-Commands****************
1-> Helm list a
2-> kubectl get nodes -o wide
3-> kubectl describe pod java-apitest-release-5bbcb584b5-vps4r --namespace default
4-> sudo systemctl restart kubelet
5-> sudo systemctl status kubelet
6-> kubectl get services --namespace default
7-> curl http://$NODE_IP:$NODE_PORT
8-> kubectl logs <your-pod-name> --namespace default
9-> kubectl describe pod <pod-name> --namespace default
10-> kubectl get deployment
11-> kubectl get service
12-> helm install java-release ./java-deployment
13-> helm status java-release<name of helm project>
14-> kubectl get pod -n monitoring
15-> helm repo list
17-> helm repo remove -> repo-name
16-> helm list -> to checko release using helm list
18-> helm uninstall <release-name>
19-> kubectl get nodes -o wide
20-> Helm init
21-> Helm repo add
22-> Helm install --name <namespace> -f ./speccial-file-name 
a-> Test cluster health using Helm test
  i-> Helm test namespace
23-> kubectl get all --all-namespaces -l release=kibana
24-> helm search <nameofrepo>



                          **************************Kubernetes-COmmands*******************************



1-> kubectl logs <nameofpod>     --> For Debugging
2-> kubectl describe <nameofpod> --> For Debugging the pod
0-> kubectl describe pod <NameOfPod>
3-> kubectl get pvc
3-> kubectl get all
4-> kubectl get all -A
5-> kubectl get deploy or deployment   ---> list all NameSpace from cluster
6-> kubectl delete deploy <NameOfPod>
7-> kubectl get pods -o wide
8-> kubectl create namespace elasticsearch
9-> kubectl get pods --namespace=default -l app=elasticsearch-master -w
10-> kubectl get namespaces
11-> kubectl get pods -n or -name elasticsearch<AnyNameForNameSpace>   or ---> pod which is name of container which is running
12->  Watch all cluster members come up.
  $ kubectl get pods --namespace=default -l app=elasticsearch-master -w
2. Retrieve elastic user's password.
  $ kubectl get secrets --namespace=default elasticsearch-master-credentials -ojsonpath='{.data.password}' | base64 -d
3. Test cluster health using Helm test.
  $ helm --namespace=default test elasticsearch

13->  kubectl get pods -o wide
14-> kubectl get service kibana -n <namespace>
15-> kubectl get pods --all-namespaces
16-> kubectl get pods -n default<NameSpace>







****To login in Kubernetes Cluster****  --> Kubernetes which is a Robust-Platform

i-> minikube ssh
2-> curl <IP>

i-> Internal or External access of the deployed application in Cluster-->
Expose Your Deployed Application: After deploying your application with Helm charts, you would expose it so that it can be accessed. This could be done by creating a Service of type ClusterIP for internal access, NodePort for external access on a specific port, or LoadBalancer for external access with a load balancer provided by your cloud provide.

ii-> Prometheus and Grafana work together to render monitoring. Prometheus takes care of data fetching as a data source and feeds that data into Grafana, which can be used to visualize data with attractive dashboards.


                           ************Prometheus-Grafana******

1-> kubectl edit svc monitoring-grafana -n default
2-> kubectl edit svc monitoring-grafana -n default
3-> kubectl get svc --all-namespaces | grep grafana
4-> Side-Car -> ELK, Prometheus & Grafana. Valina -> no chnages yet

                          *************Viva-Points************

0-> Just to verify your single-node Kubernetes cluster is up and running, use:
i-> kubectl cluster-info
ii->kubectl cluster-info dump

1-> http://192.168.56.103:30375/home --> Java-deployment
2-> http://192.168.56.103:30090/ --> Prometheus
3-> http://192.168.56.103:32000/ --> Grafana
4-> helm serach repo <nameofrepo>
5-> kubectl get service elasticsearch-master -o=jsonpath='{.spec.ports[?(@.port==9200)].nodePort}'
6-> kubectl get all -l release=kibana-new
7-> kubectl get namespace
8-> kubectl delete namespace nagarro
9-> kubectl get events -n nagarro
10-> kubectl get pod -A
11-> kubectl delete pod <nameofpod>
12-> kubectl delete pod kibana-logging-d57b4b496-knfd4 -n nagarro
13-> kubectl cluster-info

  ***********************Java-application*********************

1-> Parent-Pom-> Child-Pom
2-> Import module in POM in parent-pom
3-> kubectl describe svc elasticsearch-master<POD>


4-> 127.0.0.1   localhost localhost.localdomain localhost4 localhost4.localdomain4
::1         localhost localhost.localdomain localhost6 localhost6.localdomain6
127.0.0.1   localhost
192.168.56.103   master
192.168.56.104   worker
---> vi /etc/hosts

5-->
 flux bootstrap github \
>   --owner=your-github-username \
>   --repository=your-repo \
>   --branch=main \
>   --path=clusters/my-cluster \
>   --personal
Please enter your GitHub personal access token (PAT):
[root@master ~]# flux bootstrap gitlab   --owner=Deepak_1   --repository=flux-dpcode   --branch=main   --path=clusters/my-cluster   --personal
Please enter your GitLab personal access token (PAT):

6--->

    flux bootstrap gitlab   --owner=Deepak_1   --repository=flux-dpcode   --branch=main   --path=clusters/my-cluster   --personal
Please enter your GitLab personal access token (PAT):
► connecting to https://gitlab.com
✔ repository "https://gitlab.com/Deepak_1/flux-dpcode" created
► cloning branch "main" from Git repository "https://gitlab.com/Deepak_1/flux-dpcode.git"
✔ cloned repository
► generating component manifests
✔ generated component manifests
✔ committed component manifests to "main" ("39be476a94265f3183a98fe94fc99b7291aa66c9")
► pushing component manifests to "https://gitlab.com/Deepak_1/flux-dpcode.git"
► installing components in "flux-system" namespace
✔ installed components
✔ reconciled components
► determining if source secret "flux-system/flux-system" exists
► generating source secret
✔ public key: ecdsa-sha2-nistp384 AAAAE2VjZHNhLXNoYTItbmlzdHAzODQAAAAIbmlzdHAzODQAAABhBMRu/t2gSGl6Lgo1sUbAvyMWmBdlbZsKK7cGAsU0Gqv92SvJX5ZKmS2bXAJxNO+9Q4PBz0riixsv3q+Zu0hJLBR2EVdhx/RBGpVfJMDHzJhp/a2bvZ9WntWnJK2VR/RoWA==
✔ configured deploy key "flux-system-main-flux-system-./clusters/my-cluster" for "https://gitlab.com/Deepak_1/flux-dpcode"
► applying source secret "flux-system/flux-system"
✔ reconciled source secret
► generating sync manifests
✔ generated sync manifests
✔ committed sync manifests to "main" ("14a0f98373569ea5c8dcef7c9490ded40530b7fd")
► pushing sync manifests to "https://gitlab.com/Deepak_1/flux-dpcode.git"
► applying sync manifests
✔ reconciled sync configuration
◎ waiting for GitRepository "flux-system/flux-system" to be reconciled
✔ GitRepository reconciled successfully
◎ waiting for Kustomization "flux-system/flux-system" to be reconciled
✔ Kustomization reconciled successfully
► confirming components are healthy
✔ helm-controller: deployment ready
✔ kustomize-controller: deployment ready
✔ notification-controller: deployment ready
✔ source-controller: deployment ready
✔ all components are healthy
--> Git-Repo-Url https://gitlab.com/Deepak_1/flux-dpcode.git


----> Kubernetes

1-> kubectl get events -n flux-system
2-> 



*********Importnat-Point**********
1-> remove Ip from env_variables : and make it as variable
2-> join_token, Remove Ip from this & make it a variable




*******The things which is installed while setting up K8S on Centos or On-Premise*****
##------> kubectl get pods -n kube-system
1-> Kubectl
2-> Docker-Container
3-> kubeadm
4-> kubelet
****Important configuration which needs to be configured while setting up K8S*****
5-> coredns
6-> etcd-master
7-> kube-apiserver
8-> kube-controller-manager
9-> kube-scheduler
10-> kube-proxy (K8S or Kube)


--> kubeadm init --apiserver-advertise-address $AD_ADDR --pod-network-cidr={{cidr_v}}

sudo yum install -y curl
curl -s https://fluxcd.io/install.sh | sudo bash
flux --version



                                     **********************ELK-Monitering********************


1-> Elastic-Search

i) kubectl get pods --namespace=default -l app=elasticsearch-master -w
ii) helm install elasticsearch elastic/elasticsearch --set replicas=1 --set resources.requests.memory="512Mi" --set resources.requests.cpu="500m" --set persistence.enabled=false --set service.type=NodePort
iii) kubectl delete pod <pod-name>

iv) kubectl get secrets --namespace=default elasticsearch-master-credentials -ojsonpath='{.data.username}' | base64 -d
elastic
v) [root@master ~]# kubectl get secrets --namespace=default elasticsearch-master-credentials -ojsonpath='{.data.password}' | base64 -d
ZeIrRpq4fF3b8XEY[root@master ~]#





                     *****************GTG-Session**********



1-> Pipeline concept
2-> Plan -> everything

3-> kubectl get nodes --show-lables


pipeline {
    agent any
    environment {
        IMAGE_NAME = 'dpcode72/java'
        IMAGE_TAG = '1.0'
        ANSIBLE_HOST_KEY_CHECKING = 'false'
    }
    tools {
        git 'Default'
        maven 'mvn'
    }
    stages {
        stage('Checkout') {
            steps {
                git branch: 'deploy-1', credentialsId: 'Nagarro-Gitlab', url: 'https://git.nagarro.com/GITG00641/DotNet/deepak-kumar.git'
            }
        }
        stage('Build') {
            steps {
                dir('Java') {
                    sh "mvn clean package"
                }
            }
        }
        stage('Docker-Build') {
            steps {
                dir('Java') {
                    script {
                        docker.build("${IMAGE_NAME}:${IMAGE_TAG}")
                    }
                }
            }
        }
        stage('Docker-Push') {
            steps {
                script {
                    docker.withRegistry('https://index.docker.io/v1/', 'docker-login') {
                        docker.image("${IMAGE_NAME}:${IMAGE_TAG}").push()
                    }
                }
            }
        }
    }
}

---->

pipeline {
    agent any
    environment {
        IMAGE_NAME = 'dpcode72/java'
        IMAGE_TAG = '1.0'
        ANSIBLE_HOST_KEY_CHECKING = 'false'
    }
    tools {
        git 'Default'
        maven 'mvn'
    }
    stages {
        stage('Checkout') {
            steps {
                git branch: 'deploy-1', credentialsId: 'Nagarro-Gitlab', url: 'https://git.nagarro.com/GITG00641/DotNet/deepak-kumar.git'
            }
        }
        stage('Build') {
            steps {
                dir('Java') {
                    sh "mvn clean package"
                }
            }
        }
        stage('Docker-Build') {
            steps {
                dir('Java') {
                    script {
                        docker.build("${IMAGE_NAME}:${IMAGE_TAG}")
                    }
                }
            }
        }
        stage('Docker-Push') {
            steps {
                script {
                    docker.withRegistry('https://index.docker.io/v1/', 'docker-login') {
                        docker.image("${IMAGE_NAME}:${IMAGE_TAG}").push()
                    }
                }
            }
        }
        stage('Deploy-Helm-Chart') {
            steps {
                dir('Ansible/javaDeployment') {
                    sh """
                        helm upgrade --install javaapi . --namespace java-app \
                        --set image.repository=${IMAGE_NAME},image.tag=${IMAGE_TAG}
                    """
                }
            }
        }
    }
}

---->
pipeline {
    agent any
    environment {
        IMAGE_NAME = 'dpcode72/java'
        IMAGE_TAG = '1.0'
        ANSIBLE_HOST_KEY_CHECKING = 'false'
    }
    tools {
        git 'Default'
        maven 'mvn'
    }
    stages {
        stage('Checkout') {
            steps {
                git branch: 'deploy-1', credentialsId: 'Nagarro-Gitlab', url: 'https://git.nagarro.com/GITG00641/DotNet/deepak-kumar.git'
            }
        }
        stage('Build') {
            steps {
                dir('Java') {
                    sh "mvn clean package"
                }
            }
        }
        stage('Docker-Build') {
            steps {
                dir('Java') {
                    script {
                        docker.build("${IMAGE_NAME}:${IMAGE_TAG}")
                    }
                }
            }
        }
        stage('Docker-Push') {
            steps {
                script {
                    docker.withRegistry('https://index.docker.io/v1/', 'docker-login') {
                        docker.image("${IMAGE_NAME}:${IMAGE_TAG}").push()
                    }
                }
            }
        }
        stage('Deploy-Helm-Chart') {
            steps {
                dir('ansible') {
                    withCredentials([file(credentialsId: 'kubeconfig', variable: 'KUBECONFIG_FILE')]) {
                        sh 'export KUBECONFIG=$KUBECONFIG_FILE'
                        sh """
                            helm upgrade --install my-release ../javaapi-chart --namespace java-app-namespace \
                            --set image.repository=${IMAGE_NAME},image.tag=${IMAGE_TAG}
                        """
                    }
                }
            }
        }
    }
}
---->
a) helm repo add prometheus-community https://prometheus-community.github.io/helm-charts
b) helm repo update
c) helm install monitoring prometheus-community/kube-prometheus-stack

--->
pipeline {
    agent any

    parameters {
        choice(
            name: 'MONITORING_STACK',
            choices: ['prometheus-grafana', 'elk'],
            description: 'Choose the monitoring stack to deploy'
        )
    }

    stages {
        stage('Checkout GitLab Code') {
            steps {
                checkout([$class: 'GitSCM', branches: [[name: '*/elk-grafana']],
                          userRemoteConfigs: [[url: 'https://git.nagarro.com/GITG00641/DotNet/deepak-kumar.git',
                                               credentialsId: 'Nagarro-Gitlab']]])
            }
        }

        stage('Deploy Monitoring Stack') {
            steps {
                script {
                    withCredentials([file(credentialsId: 'kubeconfig', variable: 'KUBECONFIG_FILE')]) {
                        if (params.MONITORING_STACK == 'prometheus-grafana') {
                            dir('prometheus-grafana') {
                                sh 'chmod +x deploy_prometheus_grafana.sh'
                                sh './deploy_prometheus_grafana.sh'
                            }
                        } else if (params.MONITORING_STACK == 'elk') {
                            dir('elk') {
                                sh 'kubectl apply -f .'
                            }
                        }
                    }
                }
            }
        }
    }
}
--->
pipeline {
    agent any

    parameters {
        choice(
            name: 'MONITORING_STACK',
            choices: ['prometheus-grafana', 'elk'],
            description: 'Choose the monitoring stack to deploy'
        )
    }

    stages {
        stage('Checkout GitLab Code') {
            steps {
                checkout([$class: 'GitSCM', branches: [[name: '*/elk-grafana']],
                          userRemoteConfigs: [[url: 'https://git.nagarro.com/GITG00641/DotNet/deepak-kumar.git',
                                               credentialsId: 'Nagarro-Gitlab']]])
            }
        }

        stage('Deploy Monitoring Stack') {
            steps {
                script {
                    if (params.MONITORING_STACK == 'prometheus-grafana') {
                        dir('prometheus-grafana') {
                            sh 'chmod +x deploy_prometheus_grafana.sh'
                            sh './deploy_prometheus_grafana.sh'
                        }
                    } else if (params.MONITORING_STACK == 'elk') {
                        dir('elk') {
                            sh 'kubectl apply -f .'
                        }
                    }
                }
            }
        }
    }
}
---->
pipeline {
    agent any

    parameters {
        choice(
            name: 'MONITORING_STACK',
            choices: ['prometheus-grafana', 'elk'],
            description: 'Choose the monitoring stack to deploy'
        )
    }

    stages {
        stage('Checkout GitLab Code') {
            steps {
                checkout([$class: 'GitSCM', branches: [[name: '*/elk-grafana']],
                          userRemoteConfigs: [[url: 'https://git.nagarro.com/GITG00641/DotNet/deepak-kumar.git',
                                               credentialsId: 'Nagarro-Gitlab']]])
            }
        }

        stage('Deploy Monitoring Stack') {
            steps {
                script {
                    if (params.MONITORING_STACK == 'prometheus-grafana') {
                        dir('prometheus-grafana') {
                            withCredentials([file(credentialsId: 'kubeconfig', variable: 'KUBECONFIG_FILE')]) {
                                sh 'chmod +x deploy_prometheus_grafana.sh'
                                sh './deploy_prometheus_grafana.sh'
                            }
                        }
                    } else if (params.MONITORING_STACK == 'elk') {
                        dir('elk') {
                            withCredentials([file(credentialsId: 'kubeconfig', variable: 'KUBECONFIG_FILE')]) {
                                sh 'kubectl apply -f .'
                            }
                        }
                    }
                }
            }
        }
    }
}
---->
pipeline {
    agent any

    parameters {
        choice(
            name: 'MONITORING_STACK',
            choices: ['prometheus-grafana', 'elk'],
            description: 'Choose the monitoring stack to deploy'
        )
    }

    stages {
        stage('Checkout GitLab Code') {
            steps {
                checkout([$class: 'GitSCM', branches: [[name: '*/elk-grafana']],
                          userRemoteConfigs: [[url: 'https://git.nagarro.com/GITG00641/DotNet/deepak-kumar.git',
                                               credentialsId: 'Nagarro-Gitlab']]])
            }
        }

        stage('Deploy Monitoring Stack') {
            steps {
                script {
                    withCredentials([file(credentialsId: 'dpcode', variable: 'KUBECONFIG_FILE')]) {
                        
                        
                        if (params.MONITORING_STACK == 'prometheus-grafana') {
                            dir('prometheus-grafana') {
                                sh 'chown jenkins:jenkins $KUBECONFIG_FILE'
                                sh 'chmod 600 $KUBECONFIG_FILE'
                                sh 'export KUBECONFIG=$KUBECONFIG_FILE'
                                sh 'chmod +x deploy_prometheus_grafana.sh'
                                sh './deploy_prometheus_grafana.sh'
                            }
                        } else if (params.MONITORING_STACK == 'elk') {
                            dir('Elk') {
                                sh 'chown jenkins:jenkins $KUBECONFIG_FILE'
                                sh 'chmod 600 $KUBECONFIG_FILE'
                                sh 'export KUBECONFIG=$KUBECONFIG_FILE'
                                sh 'kubectl apply -f .'
                            }
                        }
                    }
                }
            }
        }
    }
}


--->
# Run Jenkins on Kubernetes using Helm
helm repo add jenkinsci https://charts.jenkins.io
helm repo update
helm install my-jenkins jenkinsci/jenkins



--->

Certainly! I've updated the configuration for the **Prometheus service** to use a custom NodePort. Here's the modified YAML:

```yaml
apiVersion: v1
kind: Service
metadata:
  annotations:
    meta.helm.sh/release-name: prometheus
    meta.helm.sh/release-namespace: helm
  creationTimestamp: "2024-06-08T06:29:28Z"
  labels:
    app: kube-prometheus-stack-prometheus
    app.kubernetes.io/instance: prometheus
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/part-of: kube-prometheus-stack
    app.kubernetes.io/version: 60.0.1
    chart: kube-prometheus-stack-60.0.1
    heritage: Helm
    release: prometheus
    self-monitor: "true"
  name: prometheus-kube-prometheus-prometheus
  namespace: helm
  resourceVersion: "52248"
  uid: 084ecfa1-d41e-48c9-821a-5f0479e5af1a
spec:
  clusterIP: 10.100.81.133
  clusterIPs:
    - 10.100.81.133
  internalTrafficPolicy: Cluster
  ipFamilies:
    - IPv4
  ipFamilyPolicy: SingleStack
  ports:
    - name: http-web
      port: 9090
      protocol: TCP
      targetPort: 9090
      nodePort: 30000  # Custom NodePort (you can change this value)
    - appProtocol: http
      name: reloader-web
      port: 8080
      protocol: TCP
      targetPort: reloader-web
  selector:
    app.kubernetes.io/name: prometheus
    operator.prometheus.io/name: prometheus-kube-prometheus-prometheus
  sessionAffinity: None
  type: NodePort
status:
  loadBalancer: {}
```

After applying this updated configuration, Prometheus will be accessible via `http://<node-ip>:30000`. Remember to replace `<node-ip>` with the actual IP address of your Kubernetes nodes. If you're using Minikube, you can use `minikube service prometheus-kube-prometheus-prometheus` to open Prometheus in your browser. 🚀📊🎨

---->

Certainly! I've updated the configuration for the `prometheus-grafana` service to use a custom NodePort. Here's the modified YAML:

```yaml
apiVersion: v1
kind: Service
metadata:
  annotations:
    meta.helm.sh/release-name: prometheus
    meta.helm.sh/release-namespace: helm
  creationTimestamp: "2024-06-08T06:29:28Z"
  labels:
    app.kubernetes.io/instance: prometheus
    app.kubernetes.io/managed-by: Helm
    app.kubernetes.io/name: grafana
    app.kubernetes.io/version: 11.0.0
    helm.sh/chart: grafana-8.0.0
  name: prometheus-grafana
  namespace: helm
  resourceVersion: "52242"
  uid: 62300f6d-f0bc-4a9c-9885-d840c7b9e20a
spec:
  clusterIP: 10.103.172.232
  clusterIPs:
    - 10.103.172.232
  internalTrafficPolicy: Cluster
  ipFamilies:
    - IPv4
  ipFamilyPolicy: SingleStack
  ports:
    - name: http-web
      port: 80
      protocol: TCP
      targetPort: 3000
      nodePort: 30000  # Custom NodePort (you can change this value)
  selector:
    app.kubernetes.io/instance: prometheus
    app.kubernetes.io/name: grafana
  sessionAffinity: None
  type: NodePort
status:
  loadBalancer: {}
```

After applying this updated configuration, Grafana will be accessible via `http://<node-ip>:30000`. Remember to replace `<node-ip>` with the actual IP address of your Kubernetes nodes. If you're using Minikube, you can use `minikube service prometheus-grafana` to open Grafana in your browser. 🚀📊🎨

---->
 helm list -n helm
NAME            NAMESPACE       REVISION        UPDATED                                 STATUS          CHART                           APP VERSION
prometheus      helm            1               2024-06-08 02:29:04.449894034 -0400 EDT deployed        kube-prometheus-stack-60.0.1    v0.74.0
[root@master ~]# helm list -n java-app
NAME    NAMESPACE       REVISION        UPDATED                                 STATUS          CHART                   APP VERSION
javaapi java-app        3               2024-06-07 17:03:14.673258999 -0400 EDT deployed        javadeployment-0.1.0    1.16.0
[root@master ~]#








pipeline {
    agent any

    parameters {
        choice(
            name: 'MONITORING_STACK',
            choices: ['prometheus-grafana', 'elk'],
            description: 'Choose the monitoring stack to deploy'
        )
    }

    stages {
        stage('Checkout GitLab Code') {
            steps {
                checkout([$class: 'GitSCM', branches: [[name: '*/elk-grafana']],
                          userRemoteConfigs: [[url: 'https://git.nagarro.com/GITG00641/DotNet/deepak-kumar.git',
                                               credentialsId: 'Nagarro-Gitlab']]])
            }
        }

        stage('Deploy Monitoring Stack') {
            steps {
                script {
                    if (params.MONITORING_STACK == 'prometheus-grafana') {
                        dir('prometheus-grafana') {
                            withCredentials([file(credentialsId: 'dpcode', variable: 'KUBECONFIG_FILE')]) {
                                sh """
                                    chown jenkins:jenkins $KUBECONFIG_FILE
                                    chmod 600 $KUBECONFIG_FILE
                                    export KUBECONFIG=$KUBECONFIG_FILE
                                    chmod +x deploy_prometheus_grafana.sh
                                    ./deploy_prometheus_grafana.sh
                                   """

                            }
                        }
                    } else if (params.MONITORING_STACK == 'elk') {
                        dir('Elk') {
                            withCredentials([file(credentialsId: 'dpcode', variable: 'KUBECONFIG_FILE')]) {
                                sh """
                                    chown jenkins:jenkins $KUBECONFIG_FILE
                                    chmod 600 $KUBECONFIG_FILE
                                    export KUBECONFIG=$KUBECONFIG_FILE
                                    kubectl apply -f .
                                  """

                            }
                        }
                    }
                }
            }
        }
    }
}

- --iface=enp0s8
kubectl edit configmap kube-flannel-cfg -n kube-flannel


---> Communication amnong nodes--> Network connectivity

# Pluging
0-> Node Pool
1-> Calico
2-> Cni--> Kube-flannel
3-> sudo groupadd docker
4-> sudo usermod -aG docker $USER
5-> groups $USER


-----> Servie-Modification------>

1-> kubectl edit svc <nameofservice> -n namespace

******Grafana-reset-password******
2-> grafana-cli admin reset-admin-password <new-password>
3-> kubectl exec -it <grafana-pod-name> -n <namespace> -- /bin/bash
4-> kubectl describe node master

--->
 kubectl exec -it  kibana-logging-d57b4b496-tlx9h -n nagarro -- curl -XGET http://10.97.197.124:9200
{
  "name" : "elasticsearch-logging-0",
  "cluster_name" : "kubernetes-logging",
  "cluster_uuid" : "C5U1xfEFQAuf7kSK2cOMyA",
  "version" : {
    "number" : "7.3.2",
    "build_flavor" : "oss",
    "build_type" : "docker",
    "build_hash" : "1c1faf1",
    "build_date" : "2019-09-06T14:40:30.409026Z",
    "build_snapshot" : false,
    "lucene_version" : "8.1.0",
    "minimum_wire_compatibility_version" : "6.8.0",
    "minimum_index_compatibility_version" : "6.0.0-beta1"
  },
  "tagline" : "You Know, for Search"
}
[root@master Elk]#


--->
 kubectl cluster-info
Kubernetes control plane is running at https://192.168.56.106:6443
CoreDNS is running at https://192.168.56.106:6443/api/v1/namespaces/kube-system/services/kube-dns:dns/proxy

To further debug and diagnose cluster problems, use 'kubectl cluster-info dump'.
--->
 kubectl apply -f install.yaml
namespace/flux-system created
resourcequota/critical-pods created



1----->

cat service.yaml
apiVersion: v1
kind: Service
metadata:
  name: java-nodeport
spec:
  type: NodePort
  selector:
    app: java
  ports:
    - protocol: TCP
      port: 8080
      targetPort: 8080

[root@master templates]#


2---> 

 cat deployment.yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: java-deployment
  labels:
    app: java
spec:
  replicas: 1
  selector:
    matchLabels:
      app: java
  template:
    metadata:
      labels:
        app: java
    spec:
      containers:
        - name: java-container
          image: dpcode72/java-apitest:1.0
          ports:
            - containerPort: 8080

3->

 containers:
      - name: kube-flannel
        image: docker.io/flannel/flannel:v0.25.2
        command:
        - /opt/bin/flanneld
        args:
        - --ip-masq
        - --kube-subnet-mgr
        - --iface=enp0s8

#### Assignment for Jenkins

Pipelines: Jenkins : Code: git.nagarro.com
Pipeline: Types:
Admin:
Cluster creation pipeline:
Inputs: Master node, worker node
Monitoring pipeline
Input: cluster IP: master, worker node
Type of monitoring needed: Prometheus/Grafana or ELK
Deployment pipeline:
Cluster detailed as input:


-->

 name: Set hostname for kubernetes-master
      hostname:
        name: k8master
      when: inventory_hostname == 'kubernetes-master'

    - name: Set hostname for kubernetes-worker1
      hostname:
        name: k8node01
      when: inventory_hostname == 'kubernetes-worker1'

    - name: Set hostname for kubernetes-worker2
      hostname:
        name: k8node02
      when: inventory_hostname == 'kubernetes-worker2'

--->
pipeline {
    agent any
    parameters {
        choice(name: 'NODE_TYPE', choices: ['Master', 'Worker'], description: 'Select the node type to setup')
    }
    stages {
        stage('Checkout') {
             steps {
                git branch: 'k8s', credentialsId: 'Nagarro-Gitlab', url: 'https://git.nagarro.com/GITG00641/DotNet/deepak-kumar.git'
            }
        }
        stage('Provision-K8S') {
            steps {
                script {
                    if (params.NODE_TYPE == 'Master') {
                        ansiblePlaybook(playbook: 'Ansible/setup_master_node.yml')
                    } else if (params.NODE_TYPE == 'Worker') {
                        ansiblePlaybook(playbook: 'Ansible/setup_worker_nodes.yml')
                    } else {
                        error("Invalid node type selected")
                    }
                }
            }
        }
    }
}
-----> We can create or use self runner on GitLab
pipeline {
    agent any

    parameters {
        choice(name: 'NODE_TYPE', choices: ['Master', 'Worker'], description: 'Select the node type to setup')
    }

    environment {
        INVENTORY_FILE = 'Ansible/hosts'
    }

    stages {
        stage('Checkout') {
            steps {
                git branch: 'k8s', credentialsId: 'Nagarro-Gitlab', url: 'https://git.nagarro.com/GITG00641/DotNet/deepak-kumar.git'
            }
        }
        stage('Provision-K8S') {
            steps {
                script {
                    if (params.NODE_TYPE == 'Master') {
                        ansiblePlaybook(
                            playbook: 'Ansible/setup_master_node.yml', 
                            inventory: "${env.WORKSPACE}/${INVENTORY_FILE}"
                        )
                    } else if (params.NODE_TYPE == 'Worker') {
                        ansiblePlaybook(
                            playbook: 'Ansible/setup_worker_nodes.yml', 
                            inventory: "${env.WORKSPACE}/${INVENTORY_FILE}"
                        )
                    } else {
                        error("Invalid node type selected")
                    }
                }
            }
        }
    }
}

[kubernetes_master_nodes]
master ansible_host=192.168.56.106
[kubernetes_worker_nodes]
worker ansible_host=192.168.56.105



[kubernetes:children]
kubernetes_worker_nodes
kubernetes_master_nodes

[kubernetes:vars]
ansible_password=Bhardwaj#123
ansible_ssh_user=root

[all:vars]
ansible_become_pass=Bhardwaj#123





#[masters]
#master ansible_host=192.168.56.106 ansible_user=root

#[workers]
#worker ansible_host=192.168.56.105 ansible_user=root


-------------> Kubernetes-----------------------------

apiVersion: v1
clusters:
- cluster:
    certificate-authority-data: LS0tLS1CRUdJTiBDRVJUSUZJQ0FURS0tLS0tCk1JSURCVENDQWUyZ0F3SUJBZ0lJTDBhdGR0NC9vVXd3RFFZSktvWklodmNOQVFFTEJRQXdGVEVUTUJFR0ExVUUKQXhNS2EzVmlaWEp1WlhSbGN6QWVGdzB5TkRBMk1EWXhOVFV4TURSYUZ3MHpOREEyTURReE5UVTJNRFJhTUJVeApFekFSQmdOVkJBTVRDbXQxWW1WeWJtVjBaWE13Z2dFaU1BMEdDU3FHU0liM0RRRUJBUVVBQTRJQkR3QXdnZ0VLCkFvSUJBUUNaaWJnR2tNL1RHLzBrTnE2Njc3OFNjTkNGSkN0MmtyUHo5aitBL1ZoUVEvaThoRlJYSnczMTFCMG8KZy8wbk9YSmg5YnBGOGlNY2FwMjBOYnFESlllQkxBdFV1SHpyZlBxSzFKSDhDTmt1U2hsMGZEellkNGUzenNFZQpVOU92Y0IzT1pMZm1idkttaVRpVldFZ3cwRU81cWdUeGFORjVjUk1kMkFsV1Z2eVBiSkpmV1R5bVFGQldvWCs4CnNoSjI4b1NVemVjNEh3cGlaSGM2dXd5a25ZbHFCdy9Bc0N6djBGeVZLbGNvR0N0cnk1eVBkV0RmS3pCY29yM2YKRFRDY2lSNEdmbXBRdzZsdUVnVDlmYVBqSSt6OUp5QWZrRWVRTEdZRFp5c3RONVo1NGtpc1R3NG9GdElwOTg5OQpNZFBDMllvK2UyMFpsSm9oTEk4aGtqVS9ZL09uQWdNQkFBR2pXVEJYTUE0R0ExVWREd0VCL3dRRUF3SUNwREFQCkJnTlZIUk1CQWY4RUJUQURBUUgvTUIwR0ExVWREZ1FXQkJUMHZoaHBKbkxOQVdUVkg3SmF1K0xwNnVVL0NEQVYKQmdOVkhSRUVEakFNZ2dwcmRXSmxjbTVsZEdWek1BMEdDU3FHU0liM0RRRUJDd1VBQTRJQkFRQ1Y0ZGJhbk9oZwo4dFN0VEVLOTA2K2F4U0lhNmlBNCtMSjc3V1Nnc2pHaWUxSk5wWGNxT2pqNVdkNmxJS2JJZnIzQWp6NmRqMm1uCkhFb1c5YnB5cnRoTElmMkNkVnJMbkp4dEd5MEpKYk1KRzY3eU9Oa0pCbVNxUVExVlR5VHBUVk0vMllJZmhUa1QKQlg0a2h4dVR5RFA4RlFSUFBrR1VJT1ptSWNpeUl1L1dPNjFkQTRFVWFPWWpUcmorR0orWXBBbHNDejIzVnFPQgpraEFwd3VpYzRjN2tyQWZvZ3JSNmFHT3VhUHh6eERyWFhuTFk2MEdFbjNFQ0I3ZzNBRUFSVnFPeE03MEpXUFVmCkRBd1FidXlRMGtWTGhrQUY4QjhtR1l3UVpoOURZbi9uMVVGOXlEZ3Y1YzZJTGRxbzBNRW5IOEo5YnBaTnVRcnEKSGN1TldZWGlGTnMvCi0tLS0tRU5EIENFUlRJRklDQVRFLS0tLS0K
    server: https://192.168.56.106:6443
  name: kubernetes
contexts:
- context:
    cluster: kubernetes
    user: kubernetes-admin
  name: kubernetes-admin@kubernetes
current-context: kubernetes-admin@kubernetes
kind: Config
preferences: {}
users:
- name: kubernetes-admin
  user:
    client-certificate-data: LS0tLS1CRUdJTiBDRVJUSUZJQ0FURS0tLS0tCk1JSURLVENDQWhHZ0F3SUJBZ0lJVFdhTUJRWXdaZVl3RFFZSktvWklodmNOQVFFTEJRQXdGVEVUTUJFR0ExVUUKQXhNS2EzVmlaWEp1WlhSbGN6QWVGdzB5TkRBMk1EWXhOVFV4TURSYUZ3MHlOVEEyTURZeE5UVTJNVGRhTUR3eApIekFkQmdOVkJBb1RGbXQxWW1WaFpHMDZZMngxYzNSbGNpMWhaRzFwYm5NeEdUQVhCZ05WQkFNVEVHdDFZbVZ5CmJtVjBaWE10WVdSdGFXNHdnZ0VpTUEwR0NTcUdTSWIzRFFFQkFRVUFBNElCRHdBd2dnRUtBb0lCQVFDNFB1NEUKYTB0Nk5QSmZOVDNZTVVUdlljSmxabXl1VExOeFRuS3F5YjI1MTM5bjdmUmZ4MnBWVjlqMWNzL0FOZXRIL2ttcQpWV25KVEFJeEYvM0FDSmxqcUVYNkNEclpSNzhGeFZNSVVGNFJON0VtNWRacURrS1VXOStDNE5ZdDRIbkVNUTJZCm5oK2Q1bmN5c0RsYTFlTWpaZEdVTmxvbHEvK0VTWWZCeWZSTzhzSmxGK1U0N0toVXgrdVZpZWtSNGsvZk40d0UKcWxhdXk4azhJSXRiTWZWV0V5VkVtNHJwQ3lmK2VWQjZlRGRSM0ZEUjdkaS90SXJlNndObDY4MCs3MkdoT3pHTQpSRGxDeDBNR05nTjB1dHZUN1VHaTU0alk2d3psY3ljSzE4OU8vZys1aVlpb2tBRHhzd3B6TStMQ1EvUU9ON0JqClljSWN5eVBaQ2M5MW5sUTVBZ01CQUFHalZqQlVNQTRHQTFVZER3RUIvd1FFQXdJRm9EQVRCZ05WSFNVRUREQUsKQmdnckJnRUZCUWNEQWpBTUJnTlZIUk1CQWY4RUFqQUFNQjhHQTFVZEl3UVlNQmFBRlBTK0dHa21jczBCWk5VZgpzbHE3NHVucTVUOElNQTBHQ1NxR1NJYjNEUUVCQ3dVQUE0SUJBUUJBYWZ5K1FvWFd3bVRRUEcxUWFVcTU2VkkxCldDbmFpMmVSbVlNUXdCRHI5cTlCci9MK2lBa1VjcDBHbGsyVlE5YmJjWkdlYnNQYW9LTDN5cThzZzRCaGlweFUKM1hiZWYwMkZUOXQwdFMxMjRvUktFOHdCRFVPc011Zko4N1JlQXBsblg1eUo1SFRQQ3V3OXp4M1lDQVhXaVA2aQpLendWbHo5V3dZaUVLaXBWYnAvcDhSWGt5azdFVG5NakMwTVo5NEtkQ3FYVmtXYnB2M0RMcDJFQ1F3d042NTNTCkJwWHZGVVp1UmwwRy9oSmx6VnRLcXBES2dxazZHYTVmQ0ltTHBMTlgzdlVwRVFEdXZYTSt6bGZKVThNQ1d3dEoKMUV4U1ZCWEw5akFxRHJnOVhzVlcyZ1NEVmFkTG91NFdJRkFnY0Ftc3dkQmtDRmxBZWVndHg1cVU5U3BVCi0tLS0tRU5EIENFUlRJRklDQVRFLS0tLS0K
    client-key-data: LS0tLS1CRUdJTiBSU0EgUFJJVkFURSBLRVktLS0tLQpNSUlFb3dJQkFBS0NBUUVBdUQ3dUJHdExlalR5WHpVOTJERkU3MkhDWldac3JreXpjVTV5cXNtOXVkZC9aKzMwClg4ZHFWVmZZOVhMUHdEWHJSLzVKcWxWcHlVd0NNUmY5d0FpWlk2aEYrZ2c2MlVlL0JjVlRDRkJlRVRleEp1WFcKYWc1Q2xGdmZndURXTGVCNXhERU5tSjRmbmVaM01yQTVXdFhqSTJYUmxEWmFKYXYvaEVtSHdjbjBUdkxDWlJmbApPT3lvVk1mcmxZbnBFZUpQM3plTUJLcFdyc3ZKUENDTFd6SDFWaE1sUkp1SzZRc24vbmxRZW5nM1VkeFEwZTNZCnY3U0szdXNEWmV2TlB1OWhvVHN4akVRNVFzZERCallEZExyYjArMUJvdWVJMk9zTTVYTW5DdGZQVHY0UHVZbUkKcUpBQThiTUtjelBpd2tQMERqZXdZMkhDSE1zajJRblBkWjVVT1FJREFRQUJBb0lCQUg5a2M2cDJqWStJQUhXNApHSFRkVEM3QVIydFpNSmdyekg3eG9QTlozbWNiQzZyT3F3TjJuSjA1eW5lYjFPMnYybWpDK0NoZ09tN0dzVlZFCm8xMGVGUUVGSHExTTkzTzQyZW1oa0ZIVlQ5VlR6cGQ0bjVKaEhjUDY2a1pTTTRVeENzQ09zam51U3lvZ2FoYVEKSm5nYUg1MGdENU1OS2JPV2cydnljMzJZcCtYVll5NUhJSS94anlqYTVSYnFYK1lkdzlOQWJneS8rNzhXUlprdQpka0tVRDdraDhTN2ZRekxYajd0NTUyR3krRDQ3SXUxbGM0RHRNYjA2WjZIQ0ZiOVpsM05qOHFGd2ZTM281S3hECmRReThwY3JxNkc1Vm9pYkVyUUVSeXN2djZ0OFBJOVI4em9sajZ5cU5XRkJkNEVWN1o5Q3dkNzBEL2Qwa09ObjQKRTZXQlVFa0NnWUVBeUlhYVUyV1VaN2Yram52d1YzeUVWck1KdEEwdEJoSUhDeUhTbEV2UzV3cFRXb25McURScgo3RDJjN2RVSE9JckFsUjZzVGRvRU43cFZOWXRnM1JTOUU4SSsvbm95VDJ2QS9GcDhxdlp2MTlyZllXM2V3SHpqCmZXYjdsVjBwVXBrMmJHekE4Ujg2c0pnV2VOeE1lcjNab0FpM3lrVHVrRnhQYi80RU5Ha3VzK01DZ1lFQTZ6ZGQKdjBDbVk3ME9XQS9PaGE3VFV3ekVQMm5FU3NEa0lJMndYdVF5UGhoT21PNUR6Ky83ZVlUUElIaDdIcER4MmxFOApVVDkzVnltMnphN3JURnNsc0tidlBVK1dHNFRrWXlNNGg4YzluS3ROWVNlbjc4MURSdFQ5WlBoWFJ3TVRaMDRBCkVGMjlTSlhEcFpjWVRmUklSQkVkQWhrWWh0WjRiK3plZFA4QjZqTUNnWUI5YzhDUEZranZUcXhDSmdYcUpldUIKZGtkR3pzdHhOY3dVU2RlOWtXWmp4eEQ0M3FaOEdEZkF0NWM3TUFCeGZsVVh0ZlhrU3RaQ3F4OXQvVUhmYm44UQpJb0ZZb2NoaDZhNzE4Z0oyenZDUDRjM0kzWHp6ZmU2dzRNSGE0MHJiOHlDYVdydW0zbnZRU1lZZG5PMTRDTmhqCkI3RThLVDM3TU5VOTRuUnMrYlVQTXdLQmdHQjNmbzAzZUlZalBVVEVodEN3Mko2UTk5T0NEeTBSV3Y0MjNnU3MKMWlZOVZjN0d1UzBJb1R3L1NhdHBmaVVWRVB1V29ZUTQ0VHJ3TXJhOGJHZ09ZYkRIWmdyaEh4RCtPYVNuQjBJNApabjVnaXdXemU5NlBjbTRVWURBTzRjeVA2RjlQMEJybU53RVQyditJcmtFYVZLRUYyNzNHaVJhVDB5VWtJa0FkCmJhMmRBb0dCQUsyWEFTMFRtclN6Y3V1aXB4OUtCRGlqU3dPcUpDQWRtNjdNUjNNZVhhOEhsRkcrQ1lOeVV6MDAKWU9oaDlJbmYrZDNpOUxLRFZ4UU9iaWFqYWdCekRFb2J2T2ZYVlpHMkpMait6a0xQTWFqWU1zbkdpU0ZFczNUUgptTUpIVlY5dGxYZ2hYYXBlTDNQbXdtemhKd3UvTHF5UzR0UWw0RmJZaWNGTzVNQUFKWmdwCi0tLS0tRU5EIFJTQSBQUklWQVRFIEtFWS0tLS0tCg==


