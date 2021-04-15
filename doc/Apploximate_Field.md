
- $\vec{B}_{wave}<<\vec{B_0}$
- $\frac{\partial B_z}{\partial z}= 0$
- $\frac{\partial B_r}{\partial z}= 0$


using $\frac{\partial B_z}{\partial r}$



$\vec{B_0} = \frac{\mu_0}{4\pi}\frac{3m\frac{z}{|\vec{x}|} \vec{\hat{x}}-m \vec{e_z} }{|\vec{x}|^3} =  \frac{m\mu_0}{4\pi}\frac{3\frac{z}{|\vec{x}|} \vec{\hat{x}}- \vec{e_z} }{|\vec{x}|^3}$

$\frac{3\frac{z}{|\vec{x}|} \vec{\hat{x}}- \vec{e_z} }{|\vec{x}|^3}  = \frac{3z \vec{x}- \vec{e_z}|\vec{x}|^2 }{|\vec{x}|^5} =  \frac{3z \vec{x}- \vec{e_z}(r^2+z^2) }{(r^2+z^2)^{\frac{5}{2}}}$
// ここから！！！！！　上が本当か確かめる
$\frac{\partial B_z}{\partial r}$:


$\frac{\partial}{\partial r}  \frac{3z^2- (r^2+z^2) }{(r^2+z^2)^{\frac{5}{2}}}\vec{e_z} = \frac{-3z^2({\frac{5}{2}}(r^2+z^2)^{\frac{3}{2}}\times2r)-2r(r^2+z^2)^{\frac{5}{2}} + (r^2+z^2) ({\frac{5}{2}}(r^2+z^2)^{\frac{3}{2}}\times2r)}{(r^2+z^2)^5}\vec{e_z}$

when $z = 0$

$ = \frac{-2r^6+5r^6}{r^{10}}\vec{e_z} = 3\frac{1}{r^4}$

$\frac{\partial B_z}{\partial z}$:

$\frac{\partial}{\partial z}\frac{3z^2-(r^2+z^2) }{(r^2+z^2)^{\frac{5}{2}}} \vec{e_z} = \frac{6z(r^2+z^2)^{\frac{5}{2}} +3z^2({\frac{5}{2}}(r^2+z^2)^{\frac{3}{2}}\times2z)-2z(r^2+z^2)^{\frac{5}{2}} + (r^2+z^2) ({\frac{5}{2}}(r^2+z^2)^{\frac{3}{2}}\times2z)}{(r^2+z^2)^5}\vec{e_z}$

when $z = 0$

$ =0$

$\frac{\partial B_r}{\partial z}$:

$\frac{\partial}{\partial z}\frac{3zr}{(r^2+z^2)^{\frac{5}{2}}} \vec{e_r} = \frac{3r(r^2+z^2)^{\frac{5}{2}}-3zr({\frac{5}{2}}(r^2+z^2)^{\frac{3}{2}}\times2z)}{(r^2+z^2)^5} \vec{e_r}$

when $z = 0$
$ = \frac{3}{r^4}\vec{e_r}$
