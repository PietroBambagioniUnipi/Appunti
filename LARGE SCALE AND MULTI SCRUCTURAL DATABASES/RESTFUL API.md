- **API** (*Application Programming Interface*): its a software that allow two software to comunicate to each other
- they are interface that allow to connect two software, even that are written in different programming languages

- usually one of the app is the *server* that offer services, information, and elaborate requests, and the other is the *client* that consume it and make *request*
- Rest API get a **JSON** as a response, or XML (more rare)

- JSON is the language of communication, the API define what we can comunicate
- **endpoint**: points or port where a request is done (e.g. an URL)
- an example of request is just to put an URL in the browser, which will send a request to a server that will return to us a JSON file
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102202854.png]]


- **REST API** *REpresentational State Transfer API*, is an architectural approach for the creation of Web API based on the HTTP protocol with the following characteristic:
  - you can access to resource via an URL endpoint
  - use the JSON or XML format for exchange information
  - Stateless: the server doesn't store data on the client, to do so, each request made by the client contain all necessary information for that HTTP method associated to the request
  - implement the main HTTP CRUDs methods 

- **request messages** are composed by *four* parts:
  - request row (description of the request to implement)
  - header (additional information)
  - void row (used to indicate that the meta-information had been sent)
  - body (optional)
- example: GET google.com HTTP/1.1

- in the **answer messages** the request row is replaced by a state row with the code of the state of the request


- we need **modularity**, so we have to be able to change the backend, but nothing change if the endpoint remain the same

- HTTP CRUD methods:
  - GET: retrieve data
  - POST: write new data
  - DELETE: delete data
  - PUT: update all the data
  - PATCH: partial update of the data

- response code:
  - 200: ok
  - 202: accepted
  - 204: no content
  - 400: bad request 
  - 401: not authorized 
  - 403: forbidden
  - 404: not found
  - 429: too many requests
  - 502: bad gateway
  - 503: service unavailable
![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102195542.png]]

- **URI** (*Uniform Resource Identifier*): identify every resource with a code
  - urn: identify a resource with a unique and persistent name
  - URI should be standardized, the / indicate hierarchies, use plural noun for branches and hyphens for multiple words, use lowercase, don't use file extensions 
- you can use a URI hierarchy to represent relationship of resources

 - it is good practice to use caching and security system


- **idempotence**: if you execute the same command you obtain the same *response* (e.g. get is idempotente)

- **Payload**: data that has ben transferred through the REST API

- **query parameters**: attributes used to modify the result returned by the API, are insert at the end of the path with a ?
- **path params**: are parameters inserted in the path of the request
- **body of the request**: contains the main data of the request
- **headers**: usually used to add a key for authentication 

- request data with an API with python:
   ![[_linked_images/02.5 Magistrale/01 First Year/First Semester/immagini/Pasted image 20251102174926.png]]

- **Flask** is a python library that can be used to create API

- create an API:
``` python
	from flask import Flask, request  
	from flask_sqlalchemy import SQLAlchemy  
	app = Flask(__name__)  
	  
	  
	app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///data.db'  
	db = SQLAlchemy(app)  
	  
	  
	class Drink(db.Model):  
	    id = db.Column(db.Integer, primary_key=True)  
	    name = db.Column(db.String(80), unique=True, nullable=False)  
	    description = db.Column(db.String(120))  
	  
	    def __repr__(self):  
	        return f"{self.name} - {self.description}"  
	  
	  
	@app.route('/')  
	def index():  
	    return 'Hello!'  
	  
	  
	@app.route('/drinks')  
	def get_drinks():  
	    drinks = Drink.query.all()  
	  
	    output = []  
	    for drink in drinks:  
	        drink_data = {'name': drink.name, 'description': drink.description}  
	  
	        output.append(drink_data)  
	  
	    return {"drinks": output}  
	  
	  
	@app.route('/drinks/<id>')  
	def get_drink(id):  
	    drink = Drink.query.get_or_404(id)   
	    return {"name": drink.name, "description": drink.description}  
	  
	  
	@app.route('/drinks', methods=['POST'])  
	def add_drink():  
	    drink = Drink(name=request.json['name'],  
	                  description=request.json['description'])  
	    db.session.add(drink)  
	    db.session.commit()  
	    return {'id': drink.id}  
	  
	  
	@app.route('/drinks/<id>', methods=['DELETE'])  
	def delete_drink(id):  
	    drink = Drink.query.get(id)  
	    if drink is None:  
	        return {"error": "not found"}  
	    db.session.delete(drink)  
	    db.session.commit()  
	    return {"message": "yeet!@"}
	```

- **Postman** is a software that allow to test an API without having a real server




