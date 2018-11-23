javascript:
var http = new XMLHttpRequest();
var form = new FormData();
form.append('title', 'ABC');
form.append('content', 'ABC');
form.append('type', 2);
form.append('form', 'content');
form.append('submit', 'Post');
http.open('POST', 'post.php', true); http.send(form);
