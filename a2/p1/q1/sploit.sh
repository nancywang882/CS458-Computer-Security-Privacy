curl --cookie-jar cookie.txt --output response.txt "${1}/confirm.php?code=140A"
curl --cookie cookie.txt --data "title=haha&content=12345&type=2&form=content&submit=Post" "${1}/post.php"
