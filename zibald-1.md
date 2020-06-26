---
layout:     pagina
class:      log
title:      Zibald-1
permalink:  /zibald-1/
---

<h1>Zibald 1</h1>
<section class="elenco post">
    {% for post in site.categories.log %}
        <div class="log">
            <h3>{{ post.title }}</h3>
            
            {{ post.excerpt }}
        </div>
    {% endfor %}
</section>
