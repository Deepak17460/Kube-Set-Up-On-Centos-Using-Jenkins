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

After applying this updated configuration, Prometheus will be accessible via `http://<node-ip>:30000`. Remember to replace `<node-ip>` with the actual IP address of your Kubernetes nodes. If you're using Minikube, you can use `minikube service prometheus-kube-prometheus-prometheus` to open Prometheus in your browser. 
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

