---
layout:     default
class:      pagina
title:      Domande frequenti
permalink:  /faq/
bozza:      true
---

{% for category in site.categories %}
{% for post in site.categories.faq %}
<div class="faq">
<h3><a href="{{ post.url }}">{{ post.title }}</a></h3>
{{ post.excerpt }}
</div>
{% endfor %}
{% endfor %}
