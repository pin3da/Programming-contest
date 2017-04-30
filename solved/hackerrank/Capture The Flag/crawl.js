const base = "https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/infinite/"

var request = require('request')

seen = {}

function dfs(start) {
  if (start in seen) return
  seen[start] = true
  request(base + start, function(err, resp, body) {
    var link = /<a href=(.*?)>/
    var secret = /Secret/
    lines = body.split('\n')
    for (var i in lines) {
      line = lines[i]
      m = link.exec(line)
      if (m)
        if (!(m[1] in seen))
          dfs(m[1])

      m = secret.exec(line)
      if (m)
        console.log(line)
    }
  })
}

dfs('qds.html')
