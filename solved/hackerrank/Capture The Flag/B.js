var ans = []
for (a in keyjson) {
  $.getJSON("secret_json/"+a+".json", function(json) {
    ans.push(json["news_title"]);
  });
}
