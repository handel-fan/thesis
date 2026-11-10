# `Broadcast.lean` — deciding compatible shapes

Broadcasting allows dimensions of size `1` to expand to match another tensor, comparing dimensions from the **right**. This file handles the *shape calculation*, not data movement. It left-pads the shorter shape with `1`s, compares corresponding dimensions, and returns `Option Shape` (`some shape` on success, `none` on incompatibility). `broadcastList` generalizes this to several shapes.

```lean
def broadcast (b : Broadcast) : Option Shape :=
  matchPairs (oneExtendPrefix b)
def canBroadcast (b : Broadcast) : Bool :=
  (broadcast b).isSome
```

**Inspection method:** I read the leading `(3,2,1)` versus `(2,7)` example, then verified how `oneExtendPrefix` (68–75) feeds `matchPairs` (85–104) and the public API (106–109). I also checked the guards and `broadcastList` (124–138). Important separation: `Tensor.broadcastTo` is responsible for turning this compatibility decision into zero-stride tensor metadata.
