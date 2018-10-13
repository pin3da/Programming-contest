local N = 13
local C = 2
local tests = 10

local filename = assert(arg[1])
if arg[2] then C = assert(tonumber(arg[2])) end
if arg[3] then tests = assert(tonumber(arg[3])) end

math.randomseed(os.time())

for t = 1, tests do
  local colors = {}
  for i = 1, N do colors[i] = math.random(C) end

  local envs = {}
  local coroutines = {}

  for i = 1, N do
    local mycolors = {}
    for j = 1, N do if i ~= j then mycolors[j] = colors[j] end end
    local env = {
      N = N,
      C = C,
      myself = i,
      colors = mycolors,
      raise = coroutine.yield,
    }
    setmetatable(env, {__index = _ENV})
    envs[i] = env
    local code = assert(loadfile(filename, 't', env))
    coroutines[i] = coroutine.create(code)
  end

  local hands = {}

  for i = 1, N do
    local ok, hand = assert(coroutine.resume(coroutines[i]))
    assert(coroutine.status(coroutines[i]) == 'suspended', 'raise() was never called')
    assert(hand == true or hand == false, 'must raise true or false')
    hands[i] = hand
  end

  for i = 1, N do
    local myhands = table.move(hands, 1, N, 1, {})
    assert(coroutine.resume(coroutines[i], myhands))
    assert(coroutine.status(coroutines[i]) == 'dead', 'raise() was called twice')
    assert(envs[i].answer ~= nil, 'answer is nil')
    assert(type(envs[i].answer) == 'number', 'answer is not a number')
    assert(envs[i].answer == colors[i], 'guessed the wrong color')
  end

  print('OK')
end
