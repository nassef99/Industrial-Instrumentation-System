const Pool = require("pg").Pool;

const pool = new Pool ({
    user: "ubuntu",
    password: "password",
    host: "ec2-18-223-247-30.us-east-2.compute.amazonaws.com",
    port: 5432,
    database: "test_database"
});

module.exports = pool;