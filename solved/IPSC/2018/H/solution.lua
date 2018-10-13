up = false

if myself == 1 then
  up = colors[N] == 2
else
  sum = 0
  for i = 1, myself - 1 do
    if colors[i] == 2 then
      sum = sum + 1
    end
  end
  if sum % 2 == 1 then
    up = true
  end
end

hands = raise(up)

tmp = {}

tmp[1] = 1
if hands[2] then
  tmp[1] = 2
end

for i = 2, N - 1 do
  if hands[i] == hands[i + 1] then
    tmp[i] = 1
  else
    tmp[i] = 2
  end
end

if hands[1] then
  tmp[N] = 2
else
  tmp[N] = 1
end

answer = tmp[myself]
