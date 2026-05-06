# LAB – REST Interfaces

*Hands on experience creating applications with REST interfaces*

**References:**
- Flask library: https://flask.palletsprojects.com/en/1.1.x/
- REST API guideline: https://hackernoon.com/restful-api-designing-guidelines-the-best-practices-60e1d954e7c9

---

## Design a REST Interface

Even though there are no official guidelines for the definition of REST APIs, there are some common rules. Following those rules can help other developers to understand the structure of the REST interface and use it in their programs.

**Basic terms:**
- **Resource** – an object or representation of something. It has associated some data and a set of methods to operate (e.g. an Employee of a company: you can create, add or delete it)
- **Collections** – a set of resources, e.g. *Employees* is the collection of *Employee* resources
- **URL** – the Uniform Resource Locator and the path corresponding to the resource (through which the resource can be accessed)

---

## Endpoint Definition

The name of an endpoint should reflect only the resource or the collection associated, and **not** an action. Actions should be defined via the request method and not within the name of the resource.

**Non-compliant examples** (include both resource and action):
- `/getAllEmployees` – to get the list of the employees
- `/addNewEmployee` – to add a new employee
- `/deleteEmployee` – to remove an employee
- `/deleteAllEmployees` – to remove all the employees

**Compliant definition:**
| Method | Path | Description |
|--------|------|-------------|
| `GET` | `/employees` | Get the list of all employees (a collection) |
| `DELETE` | `/employees` | Remove all employees |
| `DELETE` | `/employees/{id}` | Remove the employee with a specific ID |
| `POST` | `/employees` | Create a new employee (data in request payload) |
| `GET` | `/employees/{id}` | Retrieve all data associated with a specific employee |

---

## General Rules

The general rules to associate actions with HTTP methods:

- **GET** – request data from the resource; must not produce any modification to the resource
- **POST** – request the creation of a new resource; data is included in the request payload
- **PUT** – request the update of the resource or the creation of a new one; data in the payload
- **DELETE** – request the deletion of a resource

A collection can be represented with its name (e.g. `/employees`), while resources within the collection can be represented with a unique ID or name (e.g. `/employees/{id}`).

---

## API Design with Swagger

Several tools exist to help with the design of REST APIs. They can be used to specify the API definition, create documentation, and even auto-generate a skeleton application. One of those is **Swagger** (https://swagger.io/).

Run a Swagger editor container on the VM:

```bash
docker run -d -p 9090:8080 swaggerapi/swagger-editor:v4.10.2
```

Open: `http://10.1.X.Y:9090/`

The editor uses the **OpenAPI** language (a YAML-based standard for REST API description). The base path can include a version string, e.g. `/v2/employees`.

**Example system: Employee management**
- Data structure: `Employee`
- Functionalities: get all employees, add an employee, get info about a single employee, delete an employee

---

## REST API Example – openapi.yaml

```yaml
openapi: 3.0.3
info:
  title: Swagger Employee
  license:
    name: Apache 2.0
  version: 1.0.11
servers:
  - url: http://10.1.1.230:8080/v2
paths:
  /employees:
    put:
      tags:
        - employee
      operationId: updateEmployee
      requestBody:
        content:
          application/json:
            schema:
              $ref: '#/components/schemas/Employee'
          application/xml:
            schema:
              $ref: '#/components/schemas/Employee'
        required: true
      responses:
        '200':
          description: Successful operation
          content:
            application/json:
              schema:
                $ref: '#/components/schemas/Employee'
            application/xml:
              schema:
                $ref: '#/components/schemas/Employee'
components:
  schemas:
    Employee:
      required:
        - name
        - photoUrls
      type: object
      properties:
        id:
          type: integer
          format: int64
          example: 10
        name:
          type: string
          example: Carlo
        photoUrls:
          type: string
          example: "http://my.org/mypic.jpg"
```

The Swagger interface can also be used to generate `curl` commands for invocation.

---

## Auto-Generated Code

The Swagger tool auto-generates a skeleton with a set of REST server functions, ready to execute when the corresponding REST method is invoked. Supported frameworks include:

- **Apache CXF** (`jaxrs-cxf`) – Java framework, packaged as a WAR file for Tomcat
- **Python Flask** (`python-flask`) – lightweight Python framework

To download the skeleton: **Generate Server → jaxrs-cxf** or **python-flask**

---

## Apache Tomcat

Apache Tomcat is an open-source implementation of the Java Servlet specification. It instantiates an HTTP server to receive requests from clients, and each **Servlet** receives a request and generates a response. Servlets are packaged in a **WAR** (Web Application) file.

---

## Python Flask

Flask is a lightweight web application framework for building REST APIs as simply as possible.
- https://www.palletsprojects.com/p/flask/
- https://flask.palletsprojects.com/en/1.1.x/

The package that Swagger produces is ready to be executed in a container.

```bash
# Copy the downloaded zip to the VM, then:
apt install unzip
unzip python-flask-server-generated.zip
```

---

## Deploy the Server

```bash
# Build the container image
docker build -t rest-server .

# Run it
docker run -p 8080:8080 -it rest-server

# Test with a browser
# http://10.1.Y.X:8080/v2/employees/0

# Test from the command line
curl -X POST "http://10.1.Y.X:8080/v2/employees" \
  -H "accept: application/json" \
  -H "Content-Type: application/json" \
  -d '{"id": 0, "name": "Jim", "photoUrls": "http://mywebsite.org/mypic.jpg"}'
```

> The implementation is missing at this stage – the server returns a placeholder response.

---

## Test the Server

Install a REST extension in your browser (e.g. **RESTED** in Firefox or Chrome).

Send a POST to add a new employee with payload:

```json
{
  "id": 0,
  "name": "Jim",
  "photoUrls": "http://jim.com/mypic.jpg"
}
```

The response will be `"do some magic!"` since the implementation is not yet filled in.

---

## Implement a Function

The implementation of functions associated with REST requests must be added to:

```
swagger_server/controllers/employee_controller.py
```

Skeleton for the POST handler:

```python
def add_employee(body):
    if connexion.request.is_json:
        body = Employee.from_dict(connexion.request.get_json())
        return 'do some magic!'
```

Add some debug prints:

```python
def add_employee(body):
    if connexion.request.is_json:
        body = Employee.from_dict(connexion.request.get_json())
        print(body.name)
        print(str(body.id))
        return 'do some magic!'
```

---

## Multi-Tier Cloud Application

```
REST Client  →  Frontend (Flask, receives and processes requests)  →  Backend (MySQL DB)
```

All containers communicate via a shared Docker network (`labnet`).

To inspect the bridge network and retrieve container IP addresses:

```bash
docker network inspect bridge
```

---

## Deploy a Database (Backend)

Create a user-defined Docker network so containers can reach each other **by name**:

```bash
docker network create labnet
```

Start MySQL – root password and initial database set via environment variables, no manual configuration needed:

```bash
docker run --name=mysql --network=labnet \
  -e MYSQL_ROOT_PASSWORD=password \
  -e MYSQL_DATABASE=company \
  -d mysql:5.7
```

> **Note:** MySQL 8+ uses `caching_sha2_password` by default, which requires the `cryptography` package in Python. Using MySQL 5.7 avoids this extra dependency.

---

## Create the Employees Table

Connect to the running MySQL container and open a client session:

```bash
docker exec -it mysql mysql -uroot -ppassword company
```

Create the employees table (the database `company` already exists):

```sql
CREATE TABLE IF NOT EXISTS `employees` (
  `id`     INT AUTO_INCREMENT,
  `name`   VARCHAR(150) NOT NULL,
  `picUrl` VARCHAR(150) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE = InnoDB;
```

---

## Configure the Frontend Container

Use **PyMySQL** – a pure-Python MySQL client, no native C libraries needed.

Add to `requirements.txt`:

```
PyMySQL
```

No changes to the `Dockerfile` are required. Rebuild the image and run the container on the shared Docker network:

```bash
docker build -t rest-server .
docker run --name=flask1 --network=labnet -p 8080:8080 -d rest-server
```

---

## New Employee (POST)

Connect to MySQL using the **container name** – no hardcoded IP address needed.

Edit `swagger_server/controllers/employee_controller.py`:

```python
import pymysql
from flask import jsonify
import socket

def add_employee(body):
    if connexion.request.is_json:
        body = Employee.from_dict(connexion.request.get_json())

        mydb = pymysql.connect(
            host="mysql",        # container name on labnet
            user="root",
            password="password",
            database="company"
        )

        # Store the data in the database
        mycursor = mydb.cursor()
        sql = "INSERT INTO employees (id, name, picUrl) VALUES (%s, %s, %s)"
        val = (body.id, body.name, body.photo_urls)
        mycursor.execute(sql, val)
        mydb.commit()

        return jsonify(server=socket.gethostname())
```

---

## Add Server Identity to the Response

Add the **container hostname** to every response for observability. This lets us see which server handled each request – useful in the load-balancing exercise below.

```python
import socket
from flask import jsonify

# At the end of the handler:
return jsonify(server=socket.gethostname())
```

---

## Add a New Employee

Build and run the container, then test manually or via RESTED:

```bash
curl -X POST "http://10.1.1.X:8080/v2/employees" \
  -H "accept: application/json" \
  -H "Content-Type: application/json" \
  -d '{"id": 0, "name": "Jim", "photoUrls": "http://mywebsite.org/mypic.jpg"}'
```

---

## Get Employee by ID (GET)

Implement `get_employee_by_id(employee_id)` in `employee_controller.py`:

```python
from flask import jsonify

def get_employee_by_id(employee_id):
    # Connect to the DB (same as above)
    ...

    # Issue the query
    sql = "SELECT * FROM employees WHERE id='{}'".format(employee_id)
    mycursor.execute(sql)
    myresult = mycursor.fetchall()
    print(myresult)

    # Return JSON response
    return jsonify(
        name=myresult[0][1],
        picUrl=myresult[0][2],
        id=myresult[0][0]
    )
```

Test:

```bash
curl -X GET "http://10.1.1.X:8080/v2/employees/1" -H "accept: application/json"
```

**Solution:** `python-flask-server.zip`

---

## HAProxy – Load Balancing

### Architecture

```
REST Client → HAProxy (:80)  →  flask1 :8080 (rest-server)  →  MySQL (labnet)
              balance            flask2 :8080 (rest-server)  →
              roundrobin
              ✔ health checks
              ✔ space uncoupling

─────────────────────  labnet (Docker user-defined network)  ─────────────────────
```

**What HAProxy adds to the multi-tier architecture:**

- **Space uncoupling** – the client sends requests to a single stable endpoint (`:80`), unaware of how many backend instances exist
- **Load balancing** – requests are distributed across Flask replicas (round-robin by default); more replicas can be added without changing the client
- **Health checks** – HAProxy monitors backends and stops routing to failed containers automatically

---

### Prepare Backend Replicas

Run two Flask instances on the shared Docker network:

```bash
docker run --name=flask1 --network=labnet -p 8081:8080 -d rest-server
docker run --name=flask2 --network=labnet -p 8082:8080 -d rest-server
```

- Containers are reachable **by name** on `labnet` (`flask1`, `flask2`)
- External ports `8081` / `8082` are for direct testing only
- HAProxy will use the internal hostnames and port `8080`

---

### HAProxy Configuration

Create the file `haproxy.cfg`:

```
frontend http_front
    bind *:80
    default_backend flask_back

backend flask_back
    balance roundrobin
    server flask1 flask1:8080 check
    server flask2 flask2:8080 check
```

Start the HAProxy container on the same Docker network:

```bash
docker run --name=haproxy --network=labnet -p 80:80 \
  -v $(pwd)/haproxy.cfg:/usr/local/etc/haproxy/haproxy.cfg:ro \
  -d haproxy:2.9
```

> The `-v` flag maps a local path to a path inside the container (volume mount).

---

### Test Load Distribution

Send multiple POST requests through the load balancer (port 80):

```bash
curl -X POST "http://10.1.1.X:80/v2/employees" \
  -H "accept: application/json" \
  -H "Content-Type: application/json" \
  -d '{"id": 0, "name": "Jim", "photoUrls": "http://mywebsite.org/mypic.jpg"}'
```

The `server` field in the JSON response should **alternate** between `flask1` and `flask2`, confirming round-robin load distribution.

---

## Without Swagger

Creating a REST application with Flask directly is straightforward:

```python
#!/usr/bin/env python
from flask import Flask, jsonify

app = Flask(__name__)

employees = [
    {
        'id': 1,
        'name': 'John',
        'picUrl': 'http://...'
    },
    # ...
]

@app.route('/v1/employees', methods=['GET'])
def get_employees():
    return jsonify(employees)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8080)
```

**Solution:** `custom-python-flask.zip`
