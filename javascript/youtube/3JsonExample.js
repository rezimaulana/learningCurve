//anything in json is valid javascript
let companies = [
    {
        "name": "Big Corporation",
        "numberOfEmployees": 10000,
        "ceo": "Mary",
        "rating": 3.6
    },
    {
        "name": "Small Startup",
        "numberOfEmployees": 3,
        "ceo": null,
        "rating": 4.3
    }
]
//most of the time when you're dealing with JSON you're going to get it back as a string and not as an actual Javascript Object
//in order to convert this JSON string into a Javascript object we need to use whats called json dot parse
console.log(companies)
//console.log(JSON.parse(companies))