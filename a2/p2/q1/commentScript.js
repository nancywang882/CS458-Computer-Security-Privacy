function fn(content) {
	var tags = document.getElementsByTagName('h2');
	var foundTag;
	for (var i = tags.length - 1; i >= 0; i--) {
		if (tags[i].textContent === content) {
			foundTag = tags[i];
			break;
		}
	}
	var postId = foundTag.firstElementChild.href.split('=')[1];
	var http = new XMLHttpRequest();
	http.open('POST', location.href+"/../vote.php?id="+postId+"&vote=1", true);
	http.send();
}
