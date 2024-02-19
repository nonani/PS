-- 코드를 입력하세요
# SELECT * from ONLINE_SALE where USER_ID = 2
SELECT USER_ID, PRODUCT_ID from ONLINE_SALE group by user_id, product_id HAVING count(USER_ID) > 1 order by USER_ID, PRODUCT_ID desc