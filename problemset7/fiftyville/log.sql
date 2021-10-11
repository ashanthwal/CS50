--basic description of the crime on the givendate and street:
--Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
--Interviews were conducted today with three witnesses who were present at the time —
--each of their interview transcripts mentions the courthouse.
SELECT description
FROM crime_scene_reports
WHERE street = 'Chamberlin Street' AND year = 2020 AND MONTH = 7 AND day = 28;

-- going over the witness interviews for more details:
SELECT transcript
FROM interviews
WHERE year = 2020 AND month = 7 AND day = 28 ;

--security footage for more exit details around the 10 min mark
-- Patrick Ernest Amber Danielle Roger Elizabeth Russell Evelyn
SELECT name
FROM people JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10
AND minute >=15 AND minute <= 25
AND activity = 'exit'
-- inspecting the atm transactions
-- Danielle Bobby Madison Ernest Roy Elizabeth Victoria Russell
-- comparing to narrow down suspects: Danielle Ernest Elizabeth russell
INTERSECT
SELECT name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE day = 28 AND month = 7 AND year = 2020 AND transaction_type = "withdraw"
AND atm_location = 'Fifer Street';

--comparing flights data for he earlist flight next day
-- suspects: Doris Roger Ernest Edward Evelyn Madison Bobby Danielle
-- narrowing down the list further: Ernest & Danielle
SELECT name
FROM people JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id = (SELECT id
FROM flights
WHERE day = 29 AND month = 7 AND year = 2020
ORDER BY hour, minute
LIMIT 1);

--checking phone call records
-- narrowing down the suspect further:  Ernest

SELECT DISTINCT name
FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE day = 28 AND month = 7 AND year = 2020 AND duration < 60 ;

-- finding the accomplice
SELECT city
FROM airports
WHERE id = (
SELECT destination_airport_id
FROM flights
WHERE day = 29 AND month = 7 AND year = 2020
ORDER BY hour, minute
LIMIT 1);

--finding the accomplice
SELECT name
FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE day = 28 AND month = 7 AND year = 2020 AND duration < 60
AND caller = (
SELECT phone_number
FROM people
WHERE name ='Ernest');





