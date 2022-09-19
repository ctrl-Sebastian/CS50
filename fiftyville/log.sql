-- Keep a log of any SQL queries you execute as you solve the mystery.
-- The thefty was on July 28 2021
-- It took place in Humphrey Street

SELECT * FROM crime_scene_reports;
--it took place at 10:15am at the bakery, 3 witnesses mentions the bakery

SELECT transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

--the thief got into a car sometime within 10 minutes after the theft, he got into a call for less then a minute
SELECT * FROM bakery_security_logs  WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND activity = "exit";
SELECT * FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

--earlier this day a witness saw him withdrawing money from the ATM on Legget Street
SELECT account_number, transaction_type, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Leggett Street";

-- they were going to take the earliest flight out of Fiftyville hthe next day and told the person from the other end of the phone to buy the tickets
SELECT * FROM airports WHERE city = "Fiftyville";

--the passports numbers and seats of their plane:
SELECT * FROM passengers WHERE flight_id = 8;

SELECT * FROM people WHERE license_plate = "94KL13X";