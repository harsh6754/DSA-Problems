SELECT id, ip
FROM ips
WHERE 
    ip REGEXP '^[0-9]+(\.[0-9]+){3}$' AND
    (
        LENGTH(SUBSTRING_INDEX(ip, '.', 1)) = 2 OR
        LENGTH(SUBSTRING_INDEX(SUBSTRING_INDEX(ip, '.', 2), '.', -1)) = 2
    )
ORDER BY id;
