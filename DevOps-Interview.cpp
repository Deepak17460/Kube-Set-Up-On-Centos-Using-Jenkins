                                           *********DevOps-Interview*********


pipeline{

agent any
 
enviroment{
}
tools{
}

stages{
stage("checkout"){
steps{

git branch:'branch-name', credentialsId:'Id', url:''
}
}
}


}


---> Follow Standrads & Best Practices

-->
useradd <nameofuser>
su <nameofuser?
-->
Security: Focuses on protecting credentials, securing infrastructure, and maintaining vigilance through monitoring and logging.
Compliance: Ensures adherence to internal and external policies, automates checks, documents procedures, and conducts regular audits.
---> 
Compliance benchmarks are sets of guidelines and best practices designed to ensure that systems and operations meet specific security, legal, and regulatory requirements

--->
These benchmarks help organizations maintain security, protect sensitive data, and adhere to industry standards. Below are some common types of compliance benchmark

-->
a-> kubectl port-forward my-pod
b-> kubectl port-forward my-pod 8080:80 8443:443 --> This is the beauty of Kubernetes

**********************In docker, delete, remove(rm) addition(add) **********************************

1-> helm delete <nameOfrelease> --> this is the faster than uninstall
2-> helm uninstall <nameOfrelease>
3-> human-readable language (YAML)
4- checks for code quality with tools like SonarQube


-----> Continuous Deployment (CD):
Tools: Jenkins, Spinnaker, GitLab CI/CD, Argo CD & Flux cd, Azure Devops, Github Action

--> Monitoring and Logging

Tools: Prometheus, Grafana, ELK Stack (Elasticsearch, Logstash, Kibana), Splunk
Use Case: Monitor applications and infrastructure. For example, using Prometheus and Grafana to monitor application performance and visualize metrics.


-->
In the "Schedule" text box, enter a cron-like schedule. Jenkins uses a syntax similar to Unix cron schedules. The format is:

-> MINUTES HOURS DAY_OF_MONTH MONTH DAY_OF_WEEK
a-> Every hour: H * * * *
b-> Daily at midnight: H H(0-2) * * *
c-> Every Friday at 6 PM: H H(18-20) * * 5
d-> Every 15 minutes: H/15 * * * *
e-> every hour 0 * * * * 
f-> daily midnight 0 0 * * *

-->
H (Hash): This symbol is used to distribute load more evenly by spreading builds across time slots, useful in a distributed Jenkins setup
--> #!/bin/bash



--->
Choosing Between Python and Shell Scripts
Task Complexity: For simple system tasks and interactions with shell commands and utilities, Shell scripts are efficient and straightforward.
Cross-Platform Needs: If your scripts need to run across different operating systems, Python's cross-platform nature makes it a better choice.
Tool Ecosystem: Consider the availability of existing tools and libraries that can facilitate your automation tasks. Python's extensive library ecosystem can sometimes provide pre-built solutions.
Team Skills and Preference: The familiarity and expertise of your team members with either Python or Shell scripting can influence your choice



--->
---
- name: Install-Apache
  hosts: dpcode
  become: yes
 
  tasks:
    - name: Gather-Package-Installtion
      ansible.builtin.package_facts:
        manager: auto
 
    - name: Install-httpd-package
      yum:
        name: httpd
        state: present
        update_cache: yes
      when: "'httpd' not in ansible_facts.packages"
 
    - name: Apache configuration file
      template:
        src: /etc/httpd/conf/httpd.conf
        dest: /etc/httpd/conf/httpd.conf
      notify: Restart Apache
 
    - name: Ensure Apache is running
      service:
        name: httpd
        state: started
        enabled: yes
 
  handlers:
    - name: Restart Apache
      service:
        name: httpd
        state: restarted

--> 
Agentless: No need to install agents on managed nodes
--> 

-->
Assessing DevOps Maturity
Organizations often assess their DevOps maturity to identify strengths, weaknesses, and areas for improvement.

--> We should always write pipeline that should be resuable


-->
General-Purpose Languages: Pulumi allows you to use familiar programming languages like Python, JavaScript, TypeScript, and Go. This can be beneficial for teams with strong software development skills, allowing them to leverage existing knowledge and tools.






                  *********************DevOps-Maturity**********************
    Worked on this to increae the area of improvment, where I addded multi stage in pipeline thorugh code. like fully automation is done by code! on one module for GitHub Action
    ---> In which I have used, Java spring Boot for Backned
               Python script
               Reactjs  --> Frontend
               MongoDb --> Database 

  

