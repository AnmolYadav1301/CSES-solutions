create database test_db;
use test_db;

create table accounts {
	account_id INT Primary key,
    name string ,
    account_balcance decimal
    };
    
insert into accounts value (1,'ram',500);